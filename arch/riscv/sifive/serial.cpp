#include "serial.hpp"

namespace kt::riscv::sifive {
    static std::byte* UART_PORT = 0x10013000;

    SiFiveUART::SiFiveUART()
    {
    }

    void SiFiveUART::enqueueData(data_type d) // enqueue a byte in OUT FIFO
    {
        *UART_PORT = std::byte { d };
    }

    SiFiveUART::data_type SiFiveUART::dequeueData() // dequeue a byte in IN FIFO
    {
        return *(UART_PORT + static_cast<std::size_t>(MemoryMap::rxdata));
    }

    static struct {
        static constexpr std::size_t listSize = 1;
        SiFiveUART list[listSize];
    } uartDev;

    static void uartAPIenumerate(ktl::buffer<serial::UART>& buffer)
    {
        for (auto i = 0; i < buffer.size() && i < uartDev.listSize; i++) 
            buffer[i] = serial::UART(i++);
    }

    [[nodiscard]]
    static serial::UART::Error uartAPIenqueue(serial::UART::id_type id, std::byte b)
    {
        // validate UART ID
        if (id >= uartDev.listSize)
            return serial::UART::Error::InternalInvalidWrite;
        
        uartDev.list[id].enqueueData(b);

        return serial::UART::Error::Ok;
    }

    [[nodiscard]] 
    static ktl::Result<std::byte, serial::UART::Error> uartAPIdequeue(serial::UART::id_type id)
    {
        // validate UART id
        if (id >= uartDev.listSize)
            return { std::byte{ 0 }, serial::UART::Error::InternalInvalidRead };

        return { uartDev.list[id].dequeueData(), serial::UART::Error::Ok };
    }

    void init()
    {        
        serial::UART::uinterface.enumerate = uartAPIenumerate;
        serial::UART::uinterface.enqueue = uartAPIenqueue;
        serial::UART::uinterface.dequeue = uartAPIdequeue;
    }
}