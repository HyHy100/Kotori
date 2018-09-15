#pragma once

#include "../regs.hpp"
#include "../security/priv.hpp"
#include "../../../kernel/errors.hpp"
#include <helpers/kdef.hpp>
#include "../../../ktl/bit.hpp"
#include "../../../ktl/array.hpp"
#include <cstdint>

namespace kt::riscv::inte {
    extern "C" KO_NAKED void enaint();

    extern "C" KO_NAKED void disint();

    enum class SyncExCodes : std::size_t {
        eUSoftware  = 0u,
        eSSoftware  = 1u,
        eHSoftware  = 2u,
        eMSoftware  = 3u,
        eUTimer     = 4u,
        eSTimer     = 5u,
        eHTimer     = 6u,
        eMTimer     = 7u,
        eUExt       = 8u,
        eSExt       = 9u,
        eHExt       = 10u,
        eMExt       = 11u
    };

    enum class AsyncExCodes : std::size_t {
        eIMisaligned    = 0u,
        eAccessFault    = 1u,
        eIIllegal       = 2u,
        eBreakpoint     = 3u,
        eLoadMisaligned = 4u,
        eLoadFault      = 5u,
        eStoreMisaligned = 6u,
        eStoreFault     = 7u,
        eEnvCallU       = 8u,
        eEnvCallS       = 9u,
        eEnvCallH       = 10u,
        eEnvCallM       = 11u
    };
}

KTR_ENUM_ALLOW_BIT_OP(kt::riscv::inte::AsyncExCodes)
KTR_ENUM_ALLOW_BIT_OP(kt::riscv::inte::SyncExCodes)

KTR_ENUM_ALLOW_ARRAY_INDEX(kt::riscv::inte::AsyncExCodes)
KTR_ENUM_ALLOW_ARRAY_INDEX(kt::riscv::inte::SyncExCodes)

namespace kt::riscv::inte {
    template<
    bool sync, 
    typename ExCode = std::conditional_t<sync, SyncExCodes, AsyncExCodes>
    >
    kt::Errors exDelegate(sec::OpModes mode, ExCode irqCode,  bool active)
    {
        std::size_t delegr;

        std::size_t onoff{ static_cast<std::size_t>(active) };

        if constexpr(sync) {
            switch(mode) {
                case sec::OpModes::eMachine: {
                    KTR_LOAD_CSR(medeleg, delegr, regs::CSR_Op::eAtomic);
                    delegr &= ~(0x1 << irqCode);
                    delegr |= 1 << irqCode;
                    KTR_STORE_CSR(medeleg, delegr, regs::CSR_Op::eAtomic);
                } break;

                case sec::OpModes::eHypervisor: {
                    KTR_LOAD_CSR(hedeleg, delegr, regs::CSR_Op::eAtomic);
                    delegr &= ~(0x1 << irqCode);
                    delegr |= onoff << irqCode;
                    KTR_STORE_CSR(hedeleg, delegr, regs::CSR_Op::eAtomic);
                } break;

                case sec::OpModes::eSupervisor: {
                    KTR_LOAD_CSR(sedeleg, delegr, regs::CSR_Op::eAtomic);
                    delegr &= ~(0x1 << irqCode);
                    delegr |= onoff << irqCode;
                    KTR_STORE_CSR(sedeleg, delegr, regs::CSR_Op::eAtomic);
                } break;

                case sec::OpModes::eUser: {
                    KTR_LOAD_CSR(uedeleg, delegr, regs::CSR_Op::eAtomic);
                    delegr &= ~(0x1 << irqCode);
                    delegr |= onoff << irqCode;
                    KTR_STORE_CSR(uedeleg, delegr, regs::CSR_Op::eAtomic);
                } break;

                default: {
                    return Errors::eInvalidParameters;
                } break;
            }
        } else {
            switch(mode) {
                case sec::OpModes::eMachine: {

                    KTR_LOAD_CSR(mideleg, delegr, regs::CSR_Op::eAtomic);
                    delegr &= ~(0x1 << irqCode);
                    delegr |= 1 << irqCode;
                    KTR_STORE_CSR(mideleg, delegr, regs::CSR_Op::eAtomic);
                } break;

                case sec::OpModes::eHypervisor: {
                    KTR_LOAD_CSR(hideleg, delegr, regs::CSR_Op::eAtomic);
                    delegr &= ~(0x1 << irqCode);
                    delegr |= onoff << irqCode;
                    KTR_STORE_CSR(hideleg, delegr, regs::CSR_Op::eAtomic);
                } break;

                case sec::OpModes::eSupervisor: {
                    KTR_LOAD_CSR(sideleg, delegr, regs::CSR_Op::eAtomic);
                    delegr &= ~(0x1 << irqCode);
                    delegr |= onoff << irqCode;
                    KTR_STORE_CSR(sideleg, delegr, regs::CSR_Op::eAtomic);
                } break;

                case sec::OpModes::eUser: {
                    KTR_LOAD_CSR(uideleg, delegr, regs::CSR_Op::eAtomic);
                    delegr &= ~(0x1 << irqCode);
                    delegr |= onoff << irqCode;
                    KTR_STORE_CSR(uideleg, delegr, regs::CSR_Op::eAtomic);
                } break;

                default: {
                    return Errors::eInvalidParameters;
                } break;
            }
        }
        
        return Errors::eOk;
    }

    typedef struct _ExSource {
        bool sync;
        SyncExCodes scode;
        AsyncExCodes acode;
    } ExSource;

    ExSource queryExCause();

    using functionType = void(*)();

    [[using gnu : aligned(4)]]
    void trapVectorHandler();

    Errors exSyncDispatch();

    Errors exAsyncDispatch();

    Errors exAssignSyncHandler(SyncExCodes code, void(*handler)());

    Errors exAssignAsyncHandler(AsyncExCodes code, void(*handler)());
}
