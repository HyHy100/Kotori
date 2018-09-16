#pragma once

#include <cstdint>

#include "../regs.hpp"
#include "../../../helpers/kdef.hpp"
#include "../../../ktl/array.hpp"
#include "../../../kernel/utility.hpp"
#include "../../tardef.hpp"

namespace kt::riscv::vm {
    using paddress = void*;
    using vpaddress = volatile void*;
    using cvpaddress = const volatile void*;

    using laddress = void*;
    using vladdress = volatile void*;
    using cvladdress = const volatile void*;

    using vpage_n = long long;

    #if defined(KTR_RV32)

    static constexpr long long pTableMask = 0x3fffff;

    typedef volatile struct alignas(4) _Sv32va {
        volatile unsigned offset : 12;
        volatile unsigned vpn : 20;
    } Sv32va;

    KTR_VALIDATE_STRUCTURE(Sv32va, 4);
    
    typedef volatile struct alignas(4) _Sv32PTE {
        volatile bool v : 1;
        volatile bool r : 1;
        volatile bool w : 1;
        volatile bool x : 1;      
        volatile bool user : 1;
        volatile bool global : 1;
        volatile bool accessed : 1;
        volatile bool dirty : 1;
        volatile unsigned softRes : 2;
        volatile unsigned ppn : 22;
    } Sv32PTE;

    KTR_VALIDATE_STRUCTURE(Sv32PTE, 4);

    alignas(sizeof(Sv32PTE)) ktl::array<Sv32PTE, 2 << 10> pageTable;

    #elif defined(KTR_RV64)

    static constexpr long long pTableMask = 0x3fffffffff;

    #if defined(SV39PTE)

    typedef volatile struct alignas(8) _Sv39va {
        volatile unsigned offset : 12;
        volatile unsigned vpn0 : 9;
        volatile unsigned vpn1 : 9;
        volatile unsigned vpn2 : 9;
    } Sv39va;
    
    KTR_VALIDATE_STRUCTURE(Sv39va, 8);

    typedef volatile struct alignas(8) _Sv39pa {
        volatile unsigned offset : 12;
        volatile unsigned ppn0 : 9;
        volatile unsigned ppn1 : 9;
        volatile unsigned ppn2 : 20;
    } Sv39pa;
    
    KTR_VALIDATE_STRUCTURE(Sv39pa, 8);

    typedef volatile struct alignas(8) _Sv39PTE {
        enum class Permission : unsigned {
            eNextLvlPtr = 0xb000u,
            eRZZ = 0xb001u,
            eRWZ = 0xb011u,
            eZZX = 0xb100u,
            eRZX = 0xb101u,
            eRWX = 0xb111u
        };
        volatile bool valid : 1;
        volatile Permission perm : 3;
        volatile bool user : 1;
        volatile bool global : 1;
        volatile bool accessed : 1;
        volatile bool dirty : 1;
        volatile unsigned softRes : 2;
        volatile unsigned ppn0 : 9;
        volatile unsigned ppn1 : 9;
        volatile unsigned ppn2 : 20;
        volatile unsigned res : 16;
    } Sv39PTE;

    KTR_VALIDATE_STRUCTURE(Sv39PTE, 8);
    
    alignas(sizeof(Sv39PTE)) ktl::array<Sv39PTE, 2 << 9> pageTable;
    
    #else

    typedef volatile struct alignas(8) _Sv48va {
        volatile unsigned offset : 12;
        volatile unsigned vpn0 : 9;
        volatile unsigned vpn1 : 9;
        volatile unsigned vpn2 : 9;
        volatile unsigned vpn3 : 9;
    } Sv48va;

    KTR_VALIDATE_STRUCTURE(Sv48va, 8);

    typedef volatile struct alignas(8) _Sv48pa {
        volatile unsigned offset : 12;
        volatile unsigned ppn0 : 9;
        volatile unsigned ppn1 : 9;
        volatile unsigned ppn2 : 9;
        volatile unsigned ppn3 : 11;
    } Sv48pa;

    KTR_VALIDATE_STRUCTURE(Sv48pa, 8);

    typedef volatile struct [[using gnu : packed, aligned(8)]] _Sv48PTE  {
        volatile bool valid : 1;
        volatile bool r : 1;
        volatile bool w : 1;
        volatile bool x : 1;
        volatile bool usr : 1;
        volatile bool global : 1;
        volatile bool accessed : 1;
        volatile bool d : 1;
        volatile unsigned softRes0 : 2;
        volatile unsigned ppn0 : 9;
        volatile unsigned ppn1 : 9;
        volatile unsigned ppn2 : 9;
        volatile unsigned ppn3 : 11;
        volatile unsigned res0 : 16;
    } Sv48PTE;

    KTR_VALIDATE_STRUCTURE(Sv48PTE, 8);

    alignas(sizeof(Sv48PTE)) ktl::array<Sv48PTE, 2 << 10> pageTable;
    
    #endif

    #endif

    typedef struct _VPTB {
        volatile long long ppn;
    } VPTB;

    typedef struct _MemoryProperties {
        enum class VMTypes : unsigned long long {
            MBare = 0u,
            Mbb = 1u,
            Mbbid = 2u,
            Sv32 = 8u,
            Sv39 = 9u,
            Sv48 = 10u,
            Sv57 [[deprecated("VM: Sv57 is not standardized yet")]] = 11u,
            Sv64 [[deprecated("VM: Sv64 is not standardized yet")]] = 12u
        };

        VMTypes vtype;
        VPTB ptbase;
    } MemoryProperties;

    static constexpr long long pageSize()
    { 
        return 4 * (1024 * 1024); 
    }

    [[using gnu : always_inline]]
    vpage_n paToPPN(const paddress phyAddress) 
    {
        return reinterpret_cast<vpage_n>(phyAddress)/pageSize();
    }

    static MemoryProperties queryMemoryProperties()
    {
        MemoryProperties capabilities;
        long long sptbr;
        KTR_LOAD_CSR(sptbr, sptbr, kt::riscv::regs::CSR_Op::eZero);
        capabilities.ptbase.ppn = sptbr & pTableMask;

        std::size_t mstatus;
        KTR_LOAD_CSR(mstatus, mstatus, kt::riscv::regs::CSR_Op::eZero);
        capabilities.vtype = static_cast<MemoryProperties::VMTypes>((mstatus >> 24) & 0xF);

        return capabilities;
    }

    void initMemory()
    {
        const auto capabilities = queryMemoryProperties();

        switch(capabilities.vtype) {
            case MemoryProperties::VMTypes::MBare: {
                aux::console << "VM: MBare is not implemented yet.\n";
            } break;
            case MemoryProperties::VMTypes::Mbb: {
                aux::console << "VM: Mbb is not implemented yet.\n";
            } break;
            case MemoryProperties::VMTypes::Mbbid: {
                aux::console << "VM: Mbbid is not implmented yet.\n";
            } break;
            case MemoryProperties::VMTypes::Sv32: {
                aux::console << "VM: SV32\n";
            } break;
            case MemoryProperties::VMTypes::Sv39: {
                aux::console << "VM: SV39\n";
            } break;
            case MemoryProperties::VMTypes::Sv48: {
                aux::console << "VM: SV48\n";
            } break;
            case MemoryProperties::VMTypes::Sv57: {
                aux::console << "VM: SV57 is not implemented yet.\n";
            } break; 
            case MemoryProperties::VMTypes::Sv64: {
                aux::console << "VM: SV64 is not implemented yet.\n";
            } break;
            default: {
                aux::console << "VM: undefined type\n";
            } break;
        }

        auto ppn = paToPPN(static_cast<cvladdress>(pageTable.data()));

        KTR_STORE_CSR(sptbr, ppn, kt::riscv::regs::CSR_Op::eZero);
    }
}