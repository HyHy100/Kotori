#pragma once

#include "../../../kernel/chardev/uart.hpp"

#include "../../../ktl/memory.hpp"
#include "../../../ktl/array.hpp"
#include "../../../ktl/utility.hpp"

#include <cstdint>
#include <cstddef>

namespace kt::riscv::sifive {
    class SiFiveUART
    {
    public:
        using data_type = std::byte;
        using alignment_type = std::uint32_t;

        SiFiveUART();
                
        ~SiFiveUART() = default;

        void enqueueData(data_type d);

        data_type dequeueData();
    private:
        enum class MemoryMap : uint32_t {
            txdata  = 0x0,
            rxdata  = 0x4,
            txctrl  = 0x8,
            rxctrl  = 0xC,
            ie      = 0x10,
            ip      = 0x14,
            div     = 0x18
        };
    };

    static void uartAPIenumerate(ktl::buffer<serial::UART>& buffer);

    [[nodiscard]]
    static serial::UART::Error uartAPIenqueue(serial::UART::id_type id, std::byte b);
    
    [[nodiscard]]
    static ktl::Result<std::byte, serial::UART::Error> uartAPIdequeue(serial::UART::id_type id);

    void init();
}
