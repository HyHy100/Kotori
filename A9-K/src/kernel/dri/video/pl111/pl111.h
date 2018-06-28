#if !defined(_PL111H_)
#define _PL111H_

#include <stdint.h>

#define PL111_IO_BASEADDR 0x10020000

#define PL111_FB_BASEADDR 0x60110000

typedef uint32_t color_t;

typedef struct {
    uint32_t x;
    uint32_t y;
    uint16_t bpp;
    color_t* data;
} _PL111_fb;

typedef struct {
    uint32_t tim0;
    uint32_t tim1;
    uint32_t tim2;
    uint32_t tim3;
    uint32_t upbase;
    uint32_t lpbase;
    uint32_t control;
    uint32_t imsc;
} _PL111_iomap;


#define MAKE_COLOR_BGR(B, G, R) (R | G << 0x8 | B << 0x10)
#define MAKE_COLOR_RGB(R, G, B) (R << 0x10 | G << 0x8 | B)

#define PL111_FORMAT_BGR (0x0 << 8)
#define PL111_FORMAT_RGB (0x1 << 8)

#define PL111_1BPP      (0x0 << 1)
#define PL111_2BPP      (0x1 << 1)
#define PL111_4BPP      (0x2 << 1)
#define PL111_8BPP      (0x3 << 1)
#define PL111_16BPP     (0x4 << 1)
#define PL111_24BPP     (0x5 << 1)
#define PL111_16BPP565  (0x6 << 1)
#define PL111_12BPP444  (0x7 << 1)

void pl111start(unsigned flags);

void putpx(uint32_t x, uint32_t y, color_t color);

void clscr(color_t color);

#endif
