// LAWO AZR 802/24: geheugenmap, I/O-latches, vectors en bekende labels.
// Draai als -preScript (voor auto-analyse).
// @category LAWO
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import java.util.*;

public class LawoSetup extends GhidraScript {

    private AddressSpace code, ext;

    private void label(AddressSpace sp, long off, String name, String comment) throws Exception {
        Address a = sp.getAddress(off);
        createLabel(a, name, true, SourceType.USER_DEFINED);
        if (comment != null) setPlateComment(a, comment);
    }

    private void func(long off, String name) throws Exception {
        Address a = code.getAddress(off);
        disassemble(a);
        Function f = getFunctionAt(a);
        if (f == null) f = createFunction(a, name);
        if (f != null) f.setName(name, SourceType.USER_DEFINED);
        else createLabel(a, name, true, SourceType.USER_DEFINED);
    }

    @Override
    public void run() throws Exception {
        code = currentProgram.getAddressFactory().getAddressSpace("CODE");
        ext  = currentProgram.getAddressFactory().getAddressSpace("EXTMEM");
        Memory mem = currentProgram.getMemory();

        // --- XDATA-geheugenmap van de AZR 802/24 ---
        if (mem.getBlock(ext.getAddress(0)) == null) {
            MemoryBlock io = mem.createUninitializedBlock("IO_LATCH_RM1", ext.getAddress(0), 8, false);
            io.setRead(true); io.setWrite(true); io.setVolatile(true);
            io.setComment("Schrijven: 74HC574-latches via 74HC138 (en tegelijk RM1). Lezen: RM1-schaduwkopie.");
            MemoryBlock rm1 = mem.createUninitializedBlock("RM1_WORK_RAM", ext.getAddress(8), 0x1000 - 8, false);
            rm1.setRead(true); rm1.setWrite(true);
            rm1.setComment("RM1 KM62256, A12-A14 aan GND: 4 KB werk-RAM, batterijgebufferd");
            MemoryBlock txt = mem.createUninitializedBlock("RM2_RM3_TEXT", ext.getAddress(0x1000), 0xF000, false);
            txt.setRead(true); txt.setWrite(true);
            txt.setComment("RM2/RM3 (RAM of tekst-EPROM), bank via bit7 latch 0x0000 (LD4). 32K-chip gespiegeld; EPROM-offset x op 0x8000+x");
        }
        label(ext, 0, "LATCH0_EZ_row_color_LED_bank",
            "IC15 74HC574 (Y0/EZ): bit0-3 AC0-3 rij, bit4 AC4 kleur/polariteit, bit5 LD2, bit6 LD3, bit7 LD4 = bank RM2/RM3");
        label(ext, 1, "LATCH1_ES_FP2800",
            "IC16 74HC574 (Y1/ES): FP2800 A0-A2, B0-B1, DATA (X11-X16) + AC5/AC6");
        label(ext, 2, "LATCH2_module_enable",
            "IC17 74HC574 (Y2): AC7-AC11 module/enable-selectie");
        label(ext, 3, "LATCH3_7SEG_802_15", "Niet op 802/24; op 802/15 7-segment D16");
        label(ext, 4, "LATCH4_802_15", null);
        label(ext, 5, "LATCH5", null);
        label(ext, 6, "LATCH6_802_15", null);
        label(ext, 7, "LATCH7", null);

        // --- Interruptvectoren ---
        String[] vn = {"RESET", "INT0", "TIMER0", "INT1", "TIMER1", "SERIAL"};
        int[] va = {0x00, 0x03, 0x0B, 0x13, 0x1B, 0x23};
        for (int i = 0; i < va.length; i++) {
            Address a = code.getAddress(va[i]);
            int op = getByte(a) & 0xFF;
            if (op != 0x02) continue;           // alleen LJMP-vectors; anders library-code
            int tgt = ((getByte(a.add(1)) & 0xFF) << 8) | (getByte(a.add(2)) & 0xFF);
            disassemble(a);
            createLabel(a, "VEC_" + vn[i], true, SourceType.USER_DEFINED);
            addEntryPoint(a);
            func(tgt, (i == 0 ? "reset_entry" : "isr_" + vn[i].toLowerCase()));
            addEntryPoint(code.getAddress(tgt));
            println("vector " + vn[i] + " -> " + Integer.toHexString(tgt));
        }

        // --- Per firmware bekende routines (uit handmatige analyse) ---
        String n = currentProgram.getName().toUpperCase();
        Map<Long, String> m = new LinkedHashMap<>();
        if (n.startsWith("ASFP")) {
            m.put(0x0100L, "telegram_dispatch");
            m.put(0x0436L, "serial_rx_tx");
            m.put(0x0568L, "timer_1ms_dot_pulse");
            m.put(0x210CL, "hw_init");
            m.put(0x231CL, "main");
            m.put(0x003AL, "is_digit");
        } else if (n.startsWith("MLAWO")) {
            m.put(0x0100L, "telegram_dispatch");
            m.put(0x1129L, "hw_init");
        } else if (n.startsWith("AZR-12C")) {
            m.put(0x0026L, "main");
            m.put(0x6E23L, "cpu_detect_80c31_80c32");
            m.put(0x6AE2L, "check_FORM_header");
        } else if (n.startsWith("DVB_AZRFR51")) {
            m.put(0x0966L, "uncalled_0966");   // nergens aangeroepen (dode code)
            m.put(0x0EF8L, "uncalled_0EF8");
        }
        for (Map.Entry<Long, String> e : m.entrySet()) {
            try { func(e.getKey(), e.getValue()); }
            catch (Exception ex) { println("label " + e.getValue() + " mislukt: " + ex); }
        }
    }
}
