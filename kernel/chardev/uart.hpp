#pragma once

#include "../../ktl/utility.hpp"
#include "../../ktl/memory.hpp"

#include <cstddef>

namespace kt::serial {    
    class UART {
    public:
        using id_type = std::size_t;

        enum class CommAccessMask {
            In = 1u,
            Out = 2u,
            Inout = 3u,
            Unknown
        };

        enum class Error : std::size_t {
            InvalidRead,
            InvalidWrite,
            Ok,
            InternalInvalidWrite,
            InternalInvalidRead
        };

        UART();

        UART(id_type id);

        UART(const char* uartbase, CommAccessMask comm);

        CommAccessMask accessMask();

        void enable(CommAccessMask commType);

        Error enqueue(std::byte byte);

        ktl::Result<std::byte, Error> dequeue();

        static void enumerate(ktl::buffer<serial::UART>& buffer);

        id_type id() const;

        static inline struct {
            void(*enumerate)(ktl::buffer<UART>&);
            Error(*enqueue)(id_type, std::byte);
            ktl::Result<std::byte, Error>(*dequeue)(id_type);
        } uinterface;
    private:
        id_type m_id;
        CommAccessMask capabilities;
    };
}