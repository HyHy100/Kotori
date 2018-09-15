#pragma once

#include <cstdint>

#include "../regs.hpp"

namespace kt::riscv {
    #if defined(RV32)
    static constexpr long long pTableMask = 0x3fffff;
    #elif defined(RV64)
    static constexpr long long pTableMask = 0x3fffffffff;
    #endif

    using paddress = void*;
    using vaddress = void*;
    using vpage_n = long long;

    typedef struct _PTableBase {
        volatile long long phyPageNumber;
    } PTableBase;

    typedef struct _MemoryCapabilities {
        enum class VirtPageTypes : std::int64_t {
            /*...*/
        };

        VirtPageTypes virtPageType;
        PTableBase pTBase;
    } MemoryCapabilities;


    static constexpr long long pageSize() 
    { 
        return 4 * (1024 * 1024); 
    }

    [[using gnu : always_inline]]
    vpage_n phyToPn(const paddress* const phyAddress) 
    {
        return phyAddress/pageSize();
    }
    

    static MemoryCapabilities queryMemoryCapabilities()
    {
        MemoryCapabilities capabilities;

        long long sptbr;

        KTR_LOAD_CSR(sptbr, sptbr, kt::riscv::regs::CSR_Op::eZero);

        capabilities.pTBase = sptbr & pTableMask;
        
        return capabilities;
    }

    void startMemory()
    {
        
    }
}