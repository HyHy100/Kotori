#include "uart.hpp"


namespace kt::serial {
    UART::UART(id_type id)
            : m_id(m_id)
    {
    }

    void UART::enumerate(ktl::buffer<serial::UART>& buffer)
    {
        uinterface.enumerate(buffer);
    }

    UART::id_type UART::id() const { return m_id; }

    std::size_t operator&(const UART::CommAccessMask left, const UART::CommAccessMask right)
    {
        return static_cast<std::size_t>(
                    static_cast<std::size_t>(left) & static_cast<std::size_t>(right)
                );
    }

    UART::UART()
        : m_id(0u), capabilities(CommAccessMask::Unknown)
    {
    }

    UART::UART(const char* uartbase, CommAccessMask comm)
        : m_id(0u), capabilities(comm)
    {
    }

    UART::CommAccessMask UART::accessMask()
    {
        return capabilities;
    }

    void UART::enable(CommAccessMask commType)
    {
        capabilities = commType;
    }

    UART::Error UART::enqueue(std::byte byte)
    {
        if ((capabilities & CommAccessMask::Out) != 0u)
            return uinterface.enqueue(id(), byte);

        return Error::InvalidWrite;
    }

    ktl::Result<std::byte, UART::Error> UART::dequeue()
    {
        if ((capabilities & CommAccessMask::In) != 0u)
            return uinterface.dequeue(id());

        return { std::byte{ 0 }, Error::InvalidWrite };
    }
}