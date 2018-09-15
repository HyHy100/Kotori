#pragma once

/*************************
*       DEFAULT TARGET
**************************/

#define KTR_TARGET_ARCH RV64

#if defined(KTR_TARGET_ARCH)

#if KTR_TARGET_ARCH == RV64
#define RV64 1

namespace kt::abstract = kt::riscv;

#elif KTR_TARGET_ARCH == RV32
#define RV32 1

namespace kt::abstract = kt::riscv;

#endif

#endif