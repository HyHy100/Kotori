#pragma once

#include "../regs.hpp"
#include "../../../helpers/kdef.hpp"
#include "../../../kernel/utility.hpp"

namespace kt::riscv::timers {
    void setNewCMP(std::int64_t value);

    void rtcTimerInit();
}