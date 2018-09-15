#pragma once

#include <cstdint>

#include "../../../ktl/bit.hpp"

namespace kt::riscv::sec {
    enum class OpModes : std::size_t {
        eMachine,
        eHypervisor,
        eSupervisor,
        eUser
    };
}

KTR_ENUM_ALLOW_BIT_OP(kt::riscv::sec::OpModes);
