#include "io.h"

void kprint(const char* str) {
    char c;
    while ((c = *str++) != '\0') serial_transfer_byte(0u, c);
}
