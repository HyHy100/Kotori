#pragma once

#include <cstdint>
#include <type_traits>

namespace kt::riscv::spike {
    class Htif {
    public:
        using data_type = std::uint8_t;

        Htif() = delete;

        enum class Device : std::uint64_t {
            eSyscllHandler = 0x0ul,
            eConsole = 0x1ul
        };

        using device_type = std::underlying_type_t<Device>;

        using cmd_undertype = std::uint8_t;

        enum class SyscllHandlerCmd : cmd_undertype {
            eQuit = 0x0ul
        };

        enum class ConsoleCmd : cmd_undertype {
            //  Take care using eQueue in platforms such as Qemu 
            // that not fully implemented it yet.
            eQueue = 0x0ul,
            ePrint = 0x1ul
        };

        static void sendDataToHost(std::int64_t c);

        static std::int64_t recvDataFromHost();
        
        static void init();
    };
}