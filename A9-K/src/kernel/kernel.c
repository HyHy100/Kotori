#include <stdint.h>

#include "string.h"
#include "dri/video/pl111/init.h"
#include "dri/serial/uart/pl011.h"
#include "irq.h"

void main() {
    print("Hello.\n");
    pl111start(0);
    asm("swi 0x015");
    while (1) {}
}
