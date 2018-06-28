#if !defined(_IRQH_)
#define _IRQH_

#ifndef __GNUC__
#error "This compiler is not supported"
#endif

#include "dri/video/pl111/pl111.h"

#define IRQ_HANDLER(IRQT)   __attribute__((isr(IRQT)))

void IRQ_HANDLER("UNDEF") undef_handler();

void IRQ_HANDLER("SWI") swi_handler();

void IRQ_HANDLER("ABORT") abt_handler();

void IRQ_HANDLER("IRQ") irq_handler();

void IRQ_HANDLER("FIQ") fiq_handler();

#endif
