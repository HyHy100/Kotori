#include "dri/video/pl111/pl111.h"
#include "dri/serial/uart/pl011.h"
#include "arch/arm/gic/1_0_0.h"
#include "utils/io.h"

#define SWI(N) asm("swi %0" : : "i"(N))

void main() {
    pl111start(0);
    pl011start();
    start_gic();
    clscr(0xFF00FF);
    SWI(0x015);
}
