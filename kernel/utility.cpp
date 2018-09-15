#include "utility.hpp"
#include "../arch/riscv/sifive/serial.hpp"
#include "../arch/riscv/dri/console/spike/htif.hpp"

namespace kt::utility {
    static std::byte* port = 0x10013000;
    static riscv::spike::HtifIO htifio;

    void printk(char* s)
    {
        //htifio.print_string(s);
        htifio.print_string("Kotori: HTIF is ok...................................");
        
        while (1) {}
    }
}
