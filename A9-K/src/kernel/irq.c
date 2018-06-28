#include "irq.h"

#include "utils/io.h"
#include "dri/serial/serial.h"


void IRQ_HANDLER("UNDEF")   undef_handler() {
    while (1) {}
}


void IRQ_HANDLER("SWI")     swi_handler() {
    kprint("swi\n");
    while (1) {}
}

void IRQ_HANDLER("ABORT")   abt_handler() {
    while (1) {}
}

void IRQ_HANDLER("IRQ")     irq_handler() {
    while (1) {}
}

void IRQ_HANDLER("FIQ")     fiq_handler() {
    while (1) {}
}
