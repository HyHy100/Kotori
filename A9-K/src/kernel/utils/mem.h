#ifndef _STRINGH_
#define _STRINGH_

#include <stdint.h>

void memset(void* dest, long size, unsigned char value)
{
    for (long i = 0; i < size; i++)
    {
        *((unsigned char*)dest++) = value;
    }
}

void memcpy(void* src, long size, void* dest)
{
    for (long i = 0; i < size; i++)
    {
        *((unsigned char*)dest++) = *((unsigned char*)src++);
    }
}

#endif
