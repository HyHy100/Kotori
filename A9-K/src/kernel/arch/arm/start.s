.equ UndMd, 0x1b
.equ UsrMd, 0x10
.equ AbtMd, 0x17
.equ IrqMd, 0x12
.equ FiqMd, 0x11

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
        b reset_handler

    .globl undef_handler_wrapper
    undef_handler_wrapper:
        b undef_handler

    .globl swi_handler_wrapper
    swi_handler_wrapper:
        b swi_handler

    .globl abt_handler_wrapper
    abt_handler_wrapper:
        b abt_handler

    .globl irq_handler_wrapper
    irq_handler_wrapper:
        b irq_handler

    .globl fiq_handler_wrapper
    fiq_handler_wrapper:
        b fiq_handler


.text
    .equ IVTaddress, 0x60000000

    copy_table:
        push {lr}
        ldr r0, =ivt_table_start
        ldmia r0!, { R2 - R9 }
        mov r1, #IVTaddress
        stmia r1!, { R2 - R9 }
        pop {pc}

    .globl reset_handler
    reset_handler:
        ldr sp, =stack_svc

        mov r0, #IVTaddress
        mcr p15,0,r0,c12,c0,0

        bl copy_table

        cps  #UndMd
    	ldr sp,=stack_und

    	cps #AbtMd
    	ldr sp,=stack_abt

    	cps #IrqMd
    	ldr sp,=stack_irq

    	cps #FiqMd
    	ldr sp,=stack_fiq

    	cps #UsrMd
    	ldr sp,=stack_usr

        bl main

        b .
