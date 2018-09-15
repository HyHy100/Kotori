#pragma once

#include <type_traits>
#include <new>

namespace ktl {
    template<typename T>
    class buffer {
    public:
        buffer()
            : m_data(nullptr), m_length(0u)
        {
        }

        buffer(T* data, std::size_t length) 
            : m_data(data), m_length(length)
        {
        }

        buffer(const buffer&) = default;

        buffer(buffer&& buffer) 
        {
            m_data = buffer.m_data;
            m_length = buffer.m_length;

            buffer.m_data = nullptr;
            buffer.m_length = 0u;
        }
        
        ~buffer() = default;

        std::size_t size() const
        {
            return m_length;
        }

        const T* data() const 
        {
            return m_data;
        }

        T& operator[](std::size_t index) {
            return m_data[index];
        }

        using type = T;
        using pointer = T*;
    private:
        T* m_data;
        std::size_t m_length;
    };

    class B {
    public:
        int c;
    };

    template<typename T>
    void buffer_default_construct(T* memory) {
        new (memory) T;
    }

    template<typename T>
    void buffer_default_construct_n(T* data, std::size_t n) {
        for (auto i = 0; i < n; i++)
            new (data++) T;
    }
}
