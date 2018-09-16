#pragma once

#include "chardev/uart.hpp"
#include "../ktl/array.hpp"
#include "../ktl/memory.hpp"
#include "sync.hpp"

namespace kt::aux {
    class Console final {
    public:
        Console() = default;

        Console(const Console&) = default;

        ~Console() = default;

        void init();

        using buffer_type = char;

        void operator<<(const char* s);
    
        void operator<<(const ktl::buffer<buffer_type>& payloadbuff);

        void operator>>(ktl::buffer<buffer_type>& extractTo);

        static inline struct {
            void(*putchar)(char c);
            char(*getchar)();
        } itf;
    private:
        sync::spinlock serializer;
    };

    inline Console console;
}