#include "pl011.h"

void print(const char* src) {
    while (*src != '\0') {
        *((uint32_t*)UART0_ADDRESS) = *src++;
    }
}
