#include "htif.hpp"

namespace kt::riscv::spike {
    extern "C" {
        volatile uint64_t tohost [[section(".htif")]];

        volatile uint64_t fromhost [[section(".htif")]];
    }
    
    void HtifIO::cputc(char c)
    {
        /*
            HTIF[to host] value encoding:
            [ 0 - 48 ] -> payload
            [ 48 : 56 ] -> command//
            [ 56 : 64 ] -> device
        */

        using encoding_type = std::uint64_t;

        encoding_type payload { static_cast<encoding_type>(c) };

        encoding_type encodedData { 
            static_cast<encoding_type>(Device::eConsole) << 56 |
            static_cast<encoding_type>(ConsoleCmd::ePrint) << 48 |
            payload
        };

        tohost = encodedData;
    }

    void HtifIO::print_string(const char* s)
    {
        while (*s) cputc(*s++);
    }
}