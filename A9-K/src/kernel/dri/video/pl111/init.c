#include "init.h"

void pl111start(unsigned flags) {
    pl111_dev.iomap = (_PL111_iomap*)PL111_IO_BASEADDR;
    pl111_dev.iomap->upbase = PL111_FB_BASEADDR;
    pl111_dev.iomap->control = 0x192b;
    pl111_dev.iomap->tim0 = 0x3f1f3cc4;
    pl111_dev.iomap->tim1 = 0x080b6257;
    pl111_dev.fb.data = (uint32_t*)PL111_FB_BASEADDR;
    //pl111_dev.fb.bpp = (short)pow(2, ((flags & (0x7 << 1)) >> 1));
    pl111_dev.fb.bpp = 24;
    pl111_dev.fb.x = 800;
    pl111_dev.fb.y = 600;
}

void putpx(uint32_t x, uint32_t y, color_t color) {
    pl111_dev.fb.data[y * pl111_dev.fb.y + x] = color;
}

void clscr(color_t color) {
    uint32_t* _fb_data = pl111_dev.fb.data;
    for (int i = 0; i < pl111_dev.fb.x * pl111_dev.fb.y; i++) {
        *(_fb_data++) = color;
    }
}
