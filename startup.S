.section .text

.globl _start
.globl stack_top

_start:
    la sp, stack_addr
    jal krnl
    
.bss
    .align 4

stack_addr:
    .skip 0x2000
