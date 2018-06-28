ENTRY(ivt_table_start)

MEMORY {
    RAM : ORIGIN = 0x60000000, LENGTH = 100M
}

SECTIONS {
    .text : {
        KEEP(*(.ivt_table))
        *(.text)
        etext = .;
    } > RAM

    .bss : {
        sbss = .;
        *(.bss)
        ebss = .;
    } > RAM

    sheap = .;
    heap = .;
    . += 0x8000;
    eheap = .;
    . += 0x8000;

    .data : {
        *(.data)
    } > RAM

    . = . + 0x8000;
    stack_svc = .;

    . = . + 0x8000;
    stack_und = .;

    . = . + 0x8000;
    stack_abt = .;

    . = . + 0x8000;
    stack_irq = .;

    . = . + 0x8000;
    stack_fiq = .;

    . = . + 0x8000;
    stack_usr = .;
}
