#include "irq.h"

#include "dri/video/pl111/init.h"

void IRQ_HANDLER("UNDEF") undef_handler() {
    while (1) {
    }
}


void IRQ_HANDLER("SWI") swi_handler() {
    clscr(0xFF00FF);
    while (1) {
    }
}

void IRQ_HANDLER("ABORT") abt_handler() {
    while (1) {
    }
}

void IRQ_HANDLER("IRQ") irq_handler() {
    while (1) {
    }
}

void IRQ_HANDLER("FIQ") fiq_handler() {
    while (1) {
    }
}

void __attribute__((naked)) _disableirq() {
    asm("cpsid I");
    asm("mov pc, lr");
}

void __attribute__((naked)) _enableirq() {
    asm("cpsie I");
    asm("mov pc, lr");
}
