#pragma once

#include <cstdint>
#include "../../helpers/kdef.hpp"
#include "../../ktl/bit.hpp"

namespace kt::riscv::regs {
    enum class CSR_Op : std::size_t {
        eZero,
        eAtomic,
        eImmediate
    };

    typedef volatile struct alignas(sizeof(std::size_t)) MIP {
        volatile bool usip : 1;
        volatile bool ssip : 1;
        volatile bool hsip : 1;
        volatile bool msip : 1;
        volatile bool utip : 1;
        volatile bool stip : 1;
        volatile bool htip : 1;
        volatile bool mtip : 1;
        volatile bool ueip : 1;
        volatile bool seip : 1;
        volatile bool heip : 1;
        volatile bool meip : 1;
    } MIP_t;

    KTR_VALIDATE_STRUCTURE(MIP, sizeof(std::size_t));

    typedef volatile struct alignas(sizeof(std::size_t)) MIE {
        volatile bool usie : 1;
        volatile bool ssie : 1;
        volatile bool hsie : 1;
        volatile bool msie : 1;
        volatile bool utie : 1;
        volatile bool stie : 1;
        volatile bool htie : 1;
        volatile bool mtie : 1;
        volatile bool ueie : 1;
        volatile bool seie : 1;
        volatile bool heie : 1;
        volatile bool meie : 1;
    } MIE_t;

    KTR_VALIDATE_STRUCTURE(MIE, sizeof(std::size_t));
}

#define KTR_STORE_REG_IMM(REG, VALUE)   asm("ldi "#REG", "#VALUE)

#define KTR_STORE_REG(REG, VALUE)   asm("ld "#REG", %0" : : "r="(VALUE))

#define KTR_READ_REG(REG, REF)  asm("ld "#REG", #0" : "r"(REF))

#define KTR_LOAD_CSR(CSR, REF, FLAGS)                       \
    static_assert(                                          \
        std::is_same_v<decltype(FLAGS), kt::riscv::regs::CSR_Op>,           \
        "KTR_LOAD_CSR: \"FLAGS\" must be of type kt::riscv::regs::CSR_Op"   \
    );                                                       \
    if ((FLAGS & kt::riscv::regs::CSR_Op::eAtomic)          \
                != kt::riscv::regs::CSR_Op::eZero) {        \
        asm volatile("csrrs %[dst], "#CSR", zero"           \
            : [dst]"=r"(REF));                              \
    } else {                                                \
        asm volatile("csrr %[dst], "#CSR : [dst]"=r"(REF)); \
    }

#define KTR_STORE_CSR(CSR, VALUE, FLAGS)                    \
    static_assert(                                          \
        std::is_same_v<decltype(FLAGS), kt::riscv::regs::CSR_Op>,           \
        "KTR_STORE_CSR: \"FLAGS\" must be of type kt::riscv::regs::CSR_Op"  \
    );                                                      \
    if ((FLAGS & kt::riscv::regs::CSR_Op::eAtomic)          \
                != kt::riscv::regs::CSR_Op::eZero) {        \
        asm volatile("csrrw zero, "#CSR", %[src]"           \
            : : [src]"r"(VALUE));                           \
    } else {                                                \
        asm volatile("csrw "#CSR", %[src]"                   \
        : : [src]"r"(VALUE));                               \
    }

KTR_ENUM_ALLOW_BIT_OP(kt::riscv::regs::CSR_Op);
