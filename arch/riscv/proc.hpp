#pragma once

#include "regs.hpp"

#include <cstdint>
#include <cstddef>

namespace kt::riscv::proc {
    typedef struct _CPUinfo {
        std::uint64_t vendorid;
        std::uint64_t archid;
        std::uint64_t isawidth;
    } CPUinfo;

    std::size_t getHartID();

    extern "C" void archKernelStart();
}
