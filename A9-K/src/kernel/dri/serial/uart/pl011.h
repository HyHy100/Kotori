#ifndef _PL011H_
#define _PL011H_

#include <stdint.h>

#define UART0_ADDRESS 0x10009000

void print(const char* src);

#endif
