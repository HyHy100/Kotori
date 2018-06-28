#if !defined(_STRINGH_)
#define _STRINGH_

#include <stdint.h>

void kmemset(void* dest, long size, unsigned char value) {
    uint8_t* _dest = (uint8_t*)dest;

    for (long i = 0; i < size; i++)
    {
        *_dest++ = value;
    }
}

void kmemcpy(const void* src, long size, void* dest) {
    const uint8_t* _src = (const uint8_t*)src;
    uint8_t* _dest = (uint8_t*)dest;

    for (long i = 0; i < size; i++)
    {
        *_dest++ = *_src++;
    }
}

#endif
