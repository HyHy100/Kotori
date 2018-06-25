ENTRY(ivt_table_start)

MEMORY {
    RAM : ORIGIN = 0x60000000, LENGTH = 100M
}

SECTIONS {
    text : {
        KEEP(*(.ivt_table))
        *(.text)
        etext = .;
    } > RAM

    data : {
        *(.rodata)
    } > RAM

    bss : {
        *(.bss)
    } > RAM
    
    . = . + 0x1000;
    stack_svc = .;

    . = . + 0x1000;
    stack_und = .;
    
    . = . + 0x1000;
    stack_abt = .;
    
    . = . + 0x1000;
    stack_irq = .;
    
    . = . + 0x1000;
    stack_fiq = .;
    
    . = . + 0x1000;
    stack_usr = .;
}