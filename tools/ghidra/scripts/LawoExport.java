// LAWO: exporteer decompilatie, functielijst, XDATA/poort-xrefs en dekking naar tekstbestanden.
// Gebruik: -postScript LawoExport.java <uitvoermap>
// @category LAWO
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class LawoExport extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File out = new File(args.length > 0 ? args[0] : ".");
        out.mkdirs();
        String name = currentProgram.getName().replaceAll("[^A-Za-z0-9_.-]", "_");
        Listing listing = currentProgram.getListing();
        FunctionManager fm = currentProgram.getFunctionManager();
        AddressFactory af = currentProgram.getAddressFactory();
        AddressSpace code = af.getAddressSpace("CODE");
        AddressSpace ext = af.getAddressSpace("EXTMEM");

        // 0. XDATA-referenties toevoegen voor MOV DPTR,#imm gevolgd door MOVX
        int added = 0;
        ReferenceManager rm0 = currentProgram.getReferenceManager();
        InstructionIterator ii = listing.getInstructions(true);
        while (ii.hasNext()) {
            Instruction ins = ii.next();
            if (!ins.getMnemonicString().equals("MOV") || ins.getNumOperands() != 2) continue;
            if (!ins.getDefaultOperandRepresentation(0).equals("DPTR")) continue;
            ghidra.program.model.scalar.Scalar sc = ins.getScalar(1);
            if (sc == null) continue;
            long val = sc.getUnsignedValue() & 0xFFFF;
            Instruction nx = ins.getNext();
            for (int k = 0; k < 3 && nx != null; k++, nx = nx.getNext()) {
                String t = nx.toString();
                if (t.startsWith("MOVX")) {
                    RefType rt = t.startsWith("MOVX @DPTR") ? RefType.WRITE : RefType.READ;
                    rm0.addMemoryReference(ins.getAddress(), ext.getAddress(val), rt, SourceType.ANALYSIS, 1);
                    added++; break;
                }
                if (t.contains("DPTR") || nx.getFlowType().isJump() || nx.getFlowType().isCall()) break;
            }
        }
        println("XDATA-referenties toegevoegd: " + added);

        // 1. Decompilatie
        DecompInterface di = new DecompInterface();
        DecompileOptions opt = new DecompileOptions();
        di.setOptions(opt);
        di.openProgram(currentProgram);
        int ok = 0, fail = 0;
        try (PrintWriter pw = new PrintWriter(new File(out, name + ".c"))) {
            pw.println("// Ghidra-decompilatie van " + currentProgram.getName());
            for (Function f : fm.getFunctions(true)) {
                if (monitor.isCancelled()) break;
                pw.println("\n// ==== " + f.getName() + " @ " + f.getEntryPoint()
                        + "  (" + f.getBody().getNumAddresses() + " bytes)");
                DecompileResults r = di.decompileFunction(f, 120, monitor);
                if (r != null && r.decompileCompleted() && r.getDecompiledFunction() != null) {
                    pw.println(r.getDecompiledFunction().getC()); ok++;
                } else {
                    pw.println("// decompilatie mislukt: " + (r == null ? "?" : r.getErrorMessage())); fail++;
                }
            }
        }
        di.dispose();

        // 2. Functielijst met callers
        try (PrintWriter pw = new PrintWriter(new File(out, name + ".functions.txt"))) {
            for (Function f : fm.getFunctions(true)) {
                Set<String> callers = new TreeSet<>();
                for (Function c : f.getCallingFunctions(monitor)) callers.add(c.getName());
                pw.printf("%s  %-32s %5d bytes  callers=%d %s%n", f.getEntryPoint(), f.getName(),
                        f.getBody().getNumAddresses(), callers.size(),
                        callers.size() <= 6 ? callers.toString() : "");
            }
        }

        // 3. Xrefs naar I/O-latches (via DPTR-referenties) en naar poorten/SFR's
        ReferenceManager rm = currentProgram.getReferenceManager();
        AddressSpace sfr = af.getAddressSpace("SFR");
        AddressSpace bits = af.getAddressSpace("BITS");
        try (PrintWriter pw = new PrintWriter(new File(out, name + ".xrefs.txt"))) {
            pw.println("== I/O-latches EXTMEM 0x0000-0x0007 (R=lezen schaduw-RAM, W=schrijven latch+RAM) ==");
            for (int i = 0; i < 8; i++) {
                for (Reference ref : rm.getReferencesTo(ext.getAddress(i))) {
                    Function f = getFunctionContaining(ref.getFromAddress());
                    pw.printf("0x%04X <- %s %-6s in %s%n", i, ref.getFromAddress(), ref.getReferenceType(),
                            f == null ? "-" : f.getName());
                }
            }
            String[][] regs = {{"SFR","90","P1"},{"SFR","b0","P3"},{"SFR","99","SBUF"},{"SFR","98","SCON"},
                {"SFR","89","TMOD"},{"SFR","8d","TH1"},{"SFR","8c","TH0"},{"SFR","87","PCON"},{"SFR","a8","IE"}};
            pw.println("\n== SFR-gebruik ==");
            for (String[] r : regs) {
                for (Reference ref : rm.getReferencesTo(sfr.getAddress(Long.parseLong(r[1], 16)))) {
                    Function f = getFunctionContaining(ref.getFromAddress());
                    pw.printf("%-5s <- %s %-10s in %s%n", r[2], ref.getFromAddress(), ref.getReferenceType(),
                            f == null ? "-" : f.getName());
                }
            }
            pw.println("\n== Poortbits P1.x / P3.x ==");
            for (int port : new int[]{0x90, 0xB0}) {
                for (int b = 0; b < 8; b++) {
                    for (Reference ref : rm.getReferencesTo(bits.getAddress(port + b))) {
                        Function f = getFunctionContaining(ref.getFromAddress());
                        pw.printf("P%d.%d <- %s %-10s in %s%n", port == 0x90 ? 1 : 3, b, ref.getFromAddress(),
                                ref.getReferenceType(), f == null ? "-" : f.getName());
                    }
                }
            }
        }

        // 4. Dekking
        long codeBytes = 0, total = 0;
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            if (b.getStart().getAddressSpace() != code || !b.isInitialized()) continue;
            total += b.getSize();
        }
        InstructionIterator it2 = listing.getInstructions(true);
        while (it2.hasNext()) codeBytes += it2.next().getLength();
        String summary = String.format("%s: %d functies, decompilatie ok=%d mislukt=%d, code %d / %d bytes",
                currentProgram.getName(), fm.getFunctionCount(), ok, fail, codeBytes, total);
        println(summary);
        try (PrintWriter pw = new PrintWriter(new FileWriter(new File(out, "SUMMARY.txt"), true))) {
            pw.println(summary);
        }
    }
}
