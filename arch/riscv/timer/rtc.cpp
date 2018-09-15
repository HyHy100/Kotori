#include "rtc.hpp"
#include "../int/inte.hpp"

namespace kt::riscv::timers {
     static constexpr auto clint_base = 0x2000000;
    
    volatile uint64_t& pmtime = *reinterpret_cast<uint64_t*>(clint_base + 0xbff8); 
    volatile uint64_t& pmtimecmp = *reinterpret_cast<uint64_t*>(clint_base + 0x4000);

    void setNewCMP(std::int64_t value) 
    {        
        pmtimecmp = pmtime + value;
        asm volatile("mv t0, %0" : : "r"(pmtime));
    }

    [[using gnu : interrupt("supervisor")]]
    static void timerIRQhandler()
    {
        while (1)
        {
            asm volatile("nop");
        }
    }

    void rtcTimerInit()
    {
        asm volatile("csrs mie,%0"::"r"((0x1 << 0x3) | (0x1 << 0x7) | (0x1 << 0xb)));

        inte::exAssignSyncHandler(inte::SyncExCodes::eMTimer, timerIRQhandler);

        setNewCMP(4000);
    }
}