#pragma once

#include <type_traits>

namespace ktl::helpers {
    template<typename Enum>
    struct EnableBitOp
    {
        using enable = std::integral_constant<bool, false>;
    };
}

#define KTR_ENUM_ALLOW_BIT_OP(Enum)                     \
template<>                                              \ 
struct ktl::helpers::EnableBitOp<Enum>                  \
{                                                       \
    using enable = std::integral_constant<bool, true>;  \
};

template<typename Enum>
constexpr typename std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator|(Enum a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<Enum>(static_cast<type>(a) | static_cast<type>(b));
}

template<typename Enum>
constexpr typename std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator&(Enum a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<Enum>(static_cast<type>(a) & static_cast<type>(b));
}

template<typename Enum>
constexpr typename std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator^(Enum a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<Enum>(static_cast<type>(a) ^ static_cast<type>(b));
}

template<typename Enum>
constexpr typename std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    bool
> operator==(Enum a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<type>(a) == static_cast<type>(b);
}

template<typename Enum>
constexpr typename std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    void
> operator&=(Enum& a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    static_cast<type&>(a) &= static_cast<type>(b);
}

template<typename Enum>
constexpr typename std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    void
> operator|=(Enum& a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    static_cast<type&>(a) |= static_cast<type>(b);
}

template<typename Enum>
constexpr typename std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator~(Enum v)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<Enum>(~static_cast<type>(v));
}

template<typename Enum>
constexpr typename std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator<<(Enum left, Enum right)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<Enum>(static_cast<type>(left) << static_cast<type>(right));
}

template<typename Enum>
constexpr typename std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator>>(Enum left, Enum right)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<type>(left) >> static_cast<type>(right);
}

template<typename Enum>
constexpr typename std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    void
> operator<<=(Enum& left, Enum right)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<type&>(left) <<= static_cast<type>(right);
}

template<typename Enum>
constexpr typename std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    void
> operator>>=(Enum& left, Enum right)
{
    using type = std::underlying_type_t<Enum>;

    return static_cast<type&>(left) >>= static_cast<type>(right);
}

//=========================================================================

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
constexpr typename std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator|(Enum a, UnderType b)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<Enum>(static_cast<type>(a) | b);
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator&(Enum a, UnderType b)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<UnderType>(static_cast<type>(a) & b);
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator^(Enum a, UnderType b)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<type>(a) ^ b;
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable,
    bool
> operator==(Enum a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<type>(a) == b;
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    void
> operator&=(Enum& a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    static_cast<type&>(a) &= b;
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    void
> operator|=(Enum& a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    static_cast<type&>(a) |= b;
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator<<(Enum left, UnderType right)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<UnderType>(static_cast<type>(left) << right);
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator>>(Enum left, UnderType right)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<Enum>(static_cast<type>(left) >> right);
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    void
> operator<<=(Enum& left, UnderType right)
{
    using type = std::underlying_type_t<Enum>;
    static_cast<type&>(left) <<= right;
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    void
> operator>>=(Enum& left, UnderType right)
{
    using type = std::underlying_type_t<Enum>;
    static_cast<type&>(left) >>= right;
}

// ======================================================================

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
constexpr typename std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator|(UnderType a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<Enum>(static_cast<UnderType>(a) | b);
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator&(UnderType a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<UnderType>(a & static_cast<type>(b));
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator^(UnderType a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    return a ^ static_cast<type>(b);
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    bool
> operator==(UnderType a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    return a == static_cast<type>(b);
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    void
> operator&=(UnderType& a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    a &= static_cast<type>(b);
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    void
> operator|=(UnderType& a, Enum b)
{
    using type = std::underlying_type_t<Enum>;
    a |= static_cast<type>(b);
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator<<(UnderType left, Enum right)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<Enum>(left << static_cast<UnderType>(right));
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    Enum
> operator>>(UnderType left, const Enum& right)
{
    using type = std::underlying_type_t<Enum>;
    return static_cast<Enum>(left >> static_cast<type>(right));
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    void
> operator<<=(UnderType& left, Enum right)
{
    using type = std::underlying_type_t<Enum>;
    left <<= static_cast<type>(right);
}

template<typename Enum, typename UnderType = std::underlying_type_t<Enum>>
typename  std::enable_if_t<
    ktl::helpers::EnableBitOp<Enum>::enable::value,
    void
> operator>>=(UnderType& left, Enum right)
{
    using type = std::underlying_type_t<Enum>;
    left >>= static_cast<type>(right);
}