#include "inte.hpp"
#include "../../../kernel/utility.hpp"

#include "../regs.hpp"

namespace kt::riscv::inte {
    void enaint() 
    {
        std::size_t mss;

        asm volatile(R"(
            mv t0, zero
            addi t0, t0, 8
            csrw mstatus, t0
            ret
        )");
    }

    void disint() 
    {
        KTR_STORE_CSR(mie, 0, regs::CSR_Op::eAtomic);
        asm volatile("ret");
    }

    [[nodiscard]]
    ExSource queryExCause()
    {
        std::size_t cause;

        KTR_LOAD_CSR(scause, cause, regs::CSR_Op::eAtomic);

        ExSource source;
        source.sync = cause > 0;
        cause <<= 1;

        if (source.sync) {
            source.scode = static_cast<SyncExCodes>(cause);
        } else {
            source.acode = static_cast<AsyncExCodes>(cause);
        }

        return source;
    }

    static ktl::array<functionType, 64> sync;
    static ktl::array<functionType, 64> async;

    kt::Errors exSyncDispatch(SyncExCodes codeidx)
    {
        using type = std::underlying_type_t<decltype(codeidx)>;

        if (static_cast<type>(codeidx) >= sync.size()) {
            return Errors::eInvalidParameters;
        }

        if (sync[codeidx] == nullptr) {
            utility::printk("exSyncDispatch: the exception handler \
                             that's being called is valid but not  \
                             implemented yet.");
            return Errors::eInvalidOperation;
        }

        sync[codeidx]();

        return Errors::eOk;
    }

    kt::Errors exAsyncDispatch(AsyncExCodes codeidx)
    {
        using type = std::underlying_type_t<decltype(codeidx)>;

        if (static_cast<type>(codeidx) >= async.size()) {
            return Errors::eInvalidParameters;
        }

        if (sync[codeidx] == nullptr) {
            utility::printk("exAsyncDispatch: the exception handler \
                             that's being called is valid but not   \
                             implemented yet.");
            return Errors::eInvalidOperation;
        }

        async[codeidx]();

        return Errors::eOk;
    }

    void trapVectorHandler()
    {
        auto cause = queryExCause();

        utility::printk("trap vector handler called\n");

        if (cause.sync) {
            [[maybe_unused]]
            volatile auto err = exSyncDispatch(cause.scode);
        } else {
            [[maybe_unused]]
            volatile auto err = exAsyncDispatch(cause.acode);
        }
    }
//
    Errors exAssignSyncHandler(SyncExCodes codeidx, void(*handler)())
    {
        using type = std::underlying_type_t<decltype(codeidx)>;

        if (static_cast<type>(codeidx) >= sync.size()) {
            return Errors::eInvalidParameters;
        }

        sync[codeidx] = handler;

        return Errors::eOk;
    }

    Errors exAssignAsyncHandler(AsyncExCodes codeidx, void(*handler)())
    {
        using type = std::underlying_type_t<decltype(codeidx)>;

        if (static_cast<type>(codeidx) >= async.size()) {
            return Errors::eInvalidParameters;
        }

        async[codeidx] = handler;

        return Errors::eOk;
    }
}