/*
    Just generic macros
*/

#include <stdint.h>
#include <assert.h>

#if !defined(_GENDEFH_)
#define _GENDEFH_

#if defined(__GNUC__)

#define _FORCED_INLINE inline __attribute__((always_inline))

#endif

typedef uint8_t byte_t;

/*
    Cast the pointer to a byte address... I think that is useful for pointer arithmetic
*/

#define ADDR2B(X) ((unsigned char*)X)

/*
    _IO = ReadWrite
    _I = ReadOnly
    _O = WriteOnly(This will be used for memory areas that will return an undefined result if you read them)
*/

#define _IO volatile
#define _I const volatile
#define _O volatile

#define io_writeoff64(BASE, OFFSET, VALUE) *((byte_t*)(ADDR2B(BASE) + OFFSET)) = VALUE

#define io_writeoff32(BASE, OFFSET, VALUE)  *((uint32_t*)(ADDR2B(BASE) + OFFSET)) = VALUE

#define io_writeoff16(BASE, OFFSET, VALUE)  *((uint16_t*)(ADDR2B(BASE) + OFFSET)) = VALUE

#define io_writeoff8(BASE, OFFSET, VALUE)   *((uint8_t*)(ADDR2B(BASE) + OFFSET))  = VALUE



#define io_readoff64(BASE, OFFSET) *((byte_t*)(ADDR2B(BASE) + OFFSET))

#define io_readoff32(BASE, OFFSET) *((uint32_t*)(ADDR2B(BASE) + OFFSET))

#define io_readoff16(BASE, OFFSET) *((uint16_t*)(ADDR2B(BASE) + OFFSET))

#define io_readoff8(BASE, OFFSET)  *((uint8_t*)(ADDR2B(BASE) + OFFSET))


#define io_writeoff(BASE, OFFSET, VALUE) _Generic((Base)                \
                                        uint8_t*    :   io_writeoff8    \
                                        uint16_t*   :   io_writeoff16   \
                                        uint32_t*   :   io_writeoff32   \
                                        uint64_t*   :   io_writeoff64   \
                                    )

#define io_readoff(BASE, OFFSET, VALUE) _Generic((Base)                 \
                                        uint8_t*    :   io_readoff8     \
                                        uint16_t*   :   io_readoff16    \
                                        uint32_t*   :   io_readoff32    \
                                        uint64_t*   :   io_readoff64    \
                                    )

#endif
