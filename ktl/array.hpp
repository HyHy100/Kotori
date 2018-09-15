#pragma once

#include <cstddef>

namespace ktl {
    namespace helpers {
        template<typename Enum>
        struct EnableArrayIndex
        {
            using enable = std::integral_constant<bool, false>;
        };
    }
    
    template<typename T, std::size_t Size>
    class array {
    public:
        array() = default;

        array(const array<T, Size>&) = default;

        array(array<T, Size>&&) = delete;

        ~array() = default;

        void fill(T e)
        {
            for (auto i = 0u; i < Size; i++) {
                m_data[i] = e;
            }
        }

        constexpr std::size_t size() const 
        {
            return Size;
        }

        const T* data() const { return m_data; }

        template<typename Enum>
        constexpr std::enable_if_t<
            ktl::helpers::EnableArrayIndex<Enum>::enable::value, 
            T&
        > 
        operator[](Enum index) {
            using type = std::underlying_type_t<Enum>;
            return m_data[static_cast<type>(index)];
        }

        using type = T;
        using pointer = T*;
    private:
        T m_data[Size];
    };
}


#define KTR_ENUM_ALLOW_ARRAY_INDEX(Enum)                \
template<>                                              \
struct ktl::helpers::EnableArrayIndex<Enum> {           \
    using enable = std::integral_constant<bool, true>;  \
};