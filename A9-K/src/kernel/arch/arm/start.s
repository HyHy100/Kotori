.section .ivt_table
    .globl ivt_table_start
    ivt_table_start:
        b reset_handler_wrapper
        b undef_handler_wrapper
        b swi_handler_wrapper
        b abt_handler_wrapper
        b abt_handler_wrapper
        nop
        b irq_handler_wrapper
        b fiq_handler_wrapper
    .globl ivt_table_end
    ivt_table_end:

    .globl reset_handler_wrapper
    reset_handler_wrapper:
        bl reset_handler

    .globl undef_handler_wrapper
    undef_handler_wrapper:
        bl undef_handler

    .globl swi_handler_wrapper
    swi_handler_wrapper:
        bl swi_handler

    .globl abt_handler_wrapper
    abt_handler_wrapper:
        bl abt_handler

    .globl irq_handler_wrapper
    irq_handler_wrapper:
        bl irq_handler

    .globl fiq_handler_wrapper
    fiq_handler_wrapper:
        bl fiq_handler


.text
    copy_table:
        push {lr}
        ldr r0, =ivt_table_start
        ldmia r0!, { R2 - R9 }
        mov r1, #0x60000000
        stmia r1!, { R2 - R9 }
        pop {pc}

    .globl reset_handler
    reset_handler:
        bl _disableirq

        ldr sp, =stack_svc

        mov r0, #0x60000000
        mcr p15,0,r0,c12,c0,0

        bl copy_table

        cps  #0x1b
    	ldr sp,=stack_und

    	cps #0x17
    	ldr sp,=stack_abt

    	cps #0x12
    	ldr sp,=stack_irq

    	cps #0x11
    	ldr sp,=stack_fiq

    	cps #0x10
    	ldr sp,=stack_usr

        bl _enableirq

        bl main
