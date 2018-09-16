#pragma once

#include "tardef.hpp"

#if defined(KTR_TARGET_ARCH)

#if KTR_TARGET_ARCH == RV64
#define KTR_RV64

namespace kt::abstract = kt::riscv;

#elif KTR_TARGET_ARCH == RV32
#define KTR_RV32

namespace kt::abstract = kt::riscv;

#endif

#endif