#pragma once

namespace kt::riscv {
    void trapHandler() 
    {
        asm volatile("li t0, 66");
    }
}
