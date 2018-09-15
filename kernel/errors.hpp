#pragma once

#include <cstdint>

namespace kt {
    enum class Errors : std::size_t {
        eInvalidOperation,
        eInvalidParameters,
        eAccessViolation,
        eOk,
        eInvalidWrite,
        eInvalidRead
    };
}