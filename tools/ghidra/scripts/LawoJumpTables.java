// LAWO: los 8051 switch-tabellen op (MOV DPTR,#T ... JMP @A+DPTR met LJMP/AJMP-tabel op T).
// Draai als -postScript vóór LawoExport.java.
// @category LAWO
import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.scalar.Scalar;
import java.util.*;
import ghidra.program.model.pcode.JumpTable;

public class LawoJumpTables extends GhidraScript {

    @Override
    public void run() throws Exception {
        AddressSpace code = currentProgram.getAddressFactory().getAddressSpace("CODE");
        long romEnd = currentProgram.getMemory().getBlock(code.getAddress(0)).getEnd().getOffset();
        Listing listing = currentProgram.getListing();
        ReferenceManager rm = currentProgram.getReferenceManager();
        Set<Address> done = new HashSet<>();
        Map<Address, List<Address>> overrides = new LinkedHashMap<>();
        int tables = 0, entries = 0;

        for (int pass = 0; pass < 20; pass++) {
            int newEntries = 0;
            List<Instruction> jmps = new ArrayList<>();
            for (Instruction ins : listing.getInstructions(true))
                if (ins.toString().equals("JMP @A+DPTR") && !done.contains(ins.getAddress())) jmps.add(ins);
            for (Instruction jmp : jmps) {
                done.add(jmp.getAddress());
                // zoek de laatste MOV DPTR,#imm in de 8 voorgaande instructies
                Long base = null;
                Instruction p = jmp.getPrevious();
                for (int k = 0; k < 8 && p != null; k++, p = p.getPrevious()) {
                    if (p.getMnemonicString().equals("MOV") && p.getNumOperands() == 2
                            && p.getDefaultOperandRepresentation(0).equals("DPTR")) {
                        Scalar s = p.getScalar(1);
                        if (s != null) base = s.getUnsignedValue() & 0xFFFF;
                        break;
                    }
                }
                if (base == null) continue;
                List<Address> targets = new ArrayList<>();
                long t = base;
                while (t + 2 <= romEnd && targets.size() < 256) {
                    int op = getByte(code.getAddress(t)) & 0xFF;
                    if (op == 0x02) {                        // LJMP hhll
                        long tgt = ((getByte(code.getAddress(t + 1)) & 0xFF) << 8) | (getByte(code.getAddress(t + 2)) & 0xFF);
                        if (tgt > romEnd || (getByte(code.getAddress(tgt)) & 0xFF) == 0xFF) break;
                        targets.add(code.getAddress(t)); t += 3;
                    } else if ((op & 0x1F) == 0x01) {        // AJMP
                        targets.add(code.getAddress(t)); t += 2;
                    } else break;
                }
                if (targets.isEmpty()) continue;
                tables++;
                for (Address e : targets) {
                    if (getInstructionAt(e) == null) { disassemble(e); newEntries++; }
                    rm.addMemoryReference(jmp.getAddress(), e, RefType.COMPUTED_JUMP, SourceType.ANALYSIS, 0);
                    entries++;
                }
                setEOLComment(jmp.getAddress(), "switch-tabel @" + Long.toHexString(base) + " (" + targets.size() + " cases)");
                overrides.put(jmp.getAddress(), new ArrayList<>(targets));
                Function f = getFunctionContaining(jmp.getAddress());
                if (f != null) CreateFunctionCmd.fixupFunctionBody(currentProgram, f, monitor);
            }
            if (newEntries == 0) break;
            analyzeChanges(currentProgram);
        }
        // functielichamen herstellen na alle nieuwe flow
        for (Function f : currentProgram.getFunctionManager().getFunctions(true))
            CreateFunctionCmd.fixupFunctionBody(currentProgram, f, monitor);
        // jumptable-overrides zodat de decompiler een switch maakt
        int ov = 0;
        for (Map.Entry<Address, List<Address>> e : overrides.entrySet()) {
            Function f = getFunctionContaining(e.getKey());
            if (f == null) continue;
            new JumpTable(e.getKey(), new ArrayList<>(e.getValue()), true, 0).writeOverride(f);
            ov++;
        }
        println("jumptable-overrides: " + ov);
        println("switch-tabellen: " + tables + ", entries: " + entries);
    }
}
