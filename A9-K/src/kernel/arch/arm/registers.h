#if !defined(_REGISTERSH_)
#define _REGISTERSH_

enum IOR {
    IOR_R0,
    IOR_R1,
    IOR_R2,
    IOR_R3,
    IOR_R4,
    IOR_R5,
    IOR_R6,
    IOR_R7,
    IOR_R8,
    IOR_R9,
    IOR_R10,
    IOR_R11,
    IOR_R12,
    IOR_R13,
};

#define io_r_imm_write(IOR, IIM)    __asm__ volatile("mov R"#IOR", "#IMM)

#define io_r_mem_write(IOR, MEM)    __asm__ volatile("str RIOR, %0" : "=r"(MEM))

#define io_r_mem_read(IOR, MEM)     __asm__ volatile("ldr RIOR, %0", : : "r"(MEM))

#endif
