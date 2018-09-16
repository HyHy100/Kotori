#include "utility.hpp"

namespace kt::aux {
    void Console::init()
    {
        serializer.init();
    }

    void Console::operator<<(const char* s)
    {
        serializer.lock();
        
        while (*s) itf.putchar(*s++);

        serializer.unlock();
    }

    void Console::operator<<(const ktl::buffer<buffer_type>& payload)
    {
        serializer.lock();

        for (auto i = 0; i < payload.size(); i++) itf.putchar(payload[i]);

        serializer.unlock();
    }

    void Console::operator>>(ktl::buffer<buffer_type>& output)
    {
        serializer.lock();
        for (std::size_t i = 0u; i < output.size(); i++) {
            if(auto c = itf.getchar(); c) {
                output[i] = c;
            } else {
                break;
            }
        }
        serializer.unlock();
    }
}
