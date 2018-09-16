#include "htif.hpp"
#include "../../../../../kernel/utility.hpp"

namespace kt::riscv::spike {
    extern "C" {
        [[gnu::section(".htif")]] volatile uint64_t tohost;

        [[gnu::section(".htif")]] volatile uint64_t fromhost;
    }
    
    void Htif::sendDataToHost(std::int64_t c)
    {
        /*
            HTIF[to host] value encoding:
            [ 0 - 48 ] -> payload
            [ 48 : 56 ] -> command//
            [ 56 : 64 ] -> device
        */

       while (tohost) { auto a = fromhost; }

       using encoding_type = std::uint64_t;

        encoding_type payload { static_cast<encoding_type>(c) };

        encoding_type encodedData { 
            static_cast<encoding_type>(Device::eConsole) << 56 |
            static_cast<encoding_type>(ConsoleCmd::ePrint) << 48 |
            payload & 0xff
        };

        tohost = encodedData;
    }

    std::int64_t Htif::recvDataFromHost()
    {
        return fromhost;
    }

    static void putchar(char c)
    {
        Htif::sendDataToHost(static_cast<std::int64_t>(c));
    }

    static char getchar()
    {
        return static_cast<char>(Htif::recvDataFromHost());
    }

    void Htif::init() 
    {
        aux::Console::itf.getchar = getchar;
        aux::Console::itf.putchar = putchar;
    }
}