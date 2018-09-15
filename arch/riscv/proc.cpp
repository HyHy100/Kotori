#include "proc.hpp"
#include "trap.h"
#include "sifive/serial.hpp"
#include "regs.hpp"
#include "timer/rtc.hpp"

#include <ktl/memory.hpp>
#include "../../kernel/utility.hpp"
#include "int/inte.hpp"

                                                                                                
namespace kt::riscv::proc {
    CPUinfo machineInfo;

    static void delegateExceptions()
    {
        // Exceptions
        
        constexpr auto sync = true;
        
        // Interrupts
        
        constexpr auto async = false;

        // Delegate interrupts to supervisor mode

        inte::exDelegate<async>(sec::OpModes::eMachine, inte::AsyncExCodes::eAccessFault, true);
        inte::exDelegate<async>(sec::OpModes::eMachine, inte::AsyncExCodes::eBreakpoint, true);
        inte::exDelegate<async>(sec::OpModes::eMachine, inte::AsyncExCodes::eEnvCallH, true);
        inte::exDelegate<async>(sec::OpModes::eMachine, inte::AsyncExCodes::eEnvCallM, true);
        inte::exDelegate<async>(sec::OpModes::eMachine, inte::AsyncExCodes::eEnvCallS, true);
        inte::exDelegate<async>(sec::OpModes::eMachine, inte::AsyncExCodes::eEnvCallU, true);
        inte::exDelegate<async>(sec::OpModes::eMachine, inte::AsyncExCodes::eIIllegal, true);
        inte::exDelegate<async>(sec::OpModes::eMachine, inte::AsyncExCodes::eIMisaligned, true);
        inte::exDelegate<async>(sec::OpModes::eMachine, inte::AsyncExCodes::eLoadFault, true);
        inte::exDelegate<async>(sec::OpModes::eMachine, inte::AsyncExCodes::eLoadMisaligned, true);
        inte::exDelegate<async>(sec::OpModes::eMachine, inte::AsyncExCodes::eStoreFault, true);
        inte::exDelegate<async>(sec::OpModes::eMachine, inte::AsyncExCodes::eStoreMisaligned, true);

        // Delegate exceptions to supervisor mode

        inte::exDelegate<sync>(sec::OpModes::eMachine, inte::SyncExCodes::eHExt, true);
        inte::exDelegate<sync>(sec::OpModes::eMachine, inte::SyncExCodes::eHSoftware, true);
        inte::exDelegate<sync>(sec::OpModes::eMachine, inte::SyncExCodes::eHTimer, true);
        inte::exDelegate<sync>(sec::OpModes::eMachine, inte::SyncExCodes::eMExt, true);
        inte::exDelegate<sync>(sec::OpModes::eMachine, inte::SyncExCodes::eMSoftware, true);
        inte::exDelegate<sync>(sec::OpModes::eMachine, inte::SyncExCodes::eMTimer, true);
        inte::exDelegate<sync>(sec::OpModes::eMachine, inte::SyncExCodes::eSExt, true);
        inte::exDelegate<sync>(sec::OpModes::eMachine, inte::SyncExCodes::eSSoftware, true);
        inte::exDelegate<sync>(sec::OpModes::eMachine, inte::SyncExCodes::eSTimer, true);
        inte::exDelegate<sync>(sec::OpModes::eMachine, inte::SyncExCodes::eUExt, true);
        inte::exDelegate<sync>(sec::OpModes::eMachine, inte::SyncExCodes::eUSoftware, true);
        inte::exDelegate<sync>(sec::OpModes::eMachine, inte::SyncExCodes::eUTimer, true);
    }

    static CPUinfo queryCPUInformation()
    {
        inte::enaint();
        constexpr uint32_t cpuextmaskb{ 0x3FFFFFF };

        CPUinfo cpuinfo;

        int misa;
        
        KTR_LOAD_CSR(misa, misa, regs::CSR_Op::eAtomic);

        auto cpuArch = (misa & ~cpuextmaskb) << 1;
    
        if (cpuArch > 0) {
            cpuinfo.isawidth = 32;
        } else if (cpuArch == 0) {
            cpuinfo.isawidth = 64;
        } else {
            cpuinfo.isawidth = 128;
        }

        //KTR_LOAD_CSR(marchid, cpuinfo.archid, regs::CSR_Op::eAtomic);
        //KTR_LOAD_CSR(mvendorid, cpuinfo.vendorid, regs::CSR_Op::eAtomic);

        return cpuinfo;
    }

    static void setTrapVector(void* trapAddress)
    {
        KTR_STORE_CSR(mtvec, reinterpret_cast<std::size_t>(trapAddress), regs::CSR_Op::eZero);
    }

    void archKernelStart()
    {
        setTrapVector(inte::trapVectorHandler);
        inte::enaint();
        
        //delegateExceptions();
        
        /*constexpr auto printSeparator = [] {
            kt::utility::printk("|\n|\n");
        };

        kt::utility::printk(
            #include "madoka.h"
        );
        
        kt::utility::printk("[K]otori: a weeaboo embedded kernel. o//o\n");
        kt::utility::printk("Collecting CPU information... \n");

        kt::utility::printk("# Arch: RISC-V\n");*/
        //printSeparator();
        
        machineInfo = queryCPUInformation();
        
        //kt::utility::printk("Info:\n");

        //printSeparator();
        //kt::utility::printk("- width: ");

        if (machineInfo.isawidth == 32) {
            kt::utility::printk("32\n");
        } else if (machineInfo.isawidth == 64) {
            kt::utility::printk("64\n");
        } else {
            kt::utility::printk("128\n");
        }

        //kt::utility::printk("Ok!\n");

        //printSeparator();

        //kt::utility::printk("Setting up trap handler... ");

        //kt::utility::printk("Ok!\n");

        //sifive::init();

        //kt::utility::printk("Initializing rtc timers... ");

        timers::rtcTimerInit();

        //kt::utility::printk("Ok!\n");

        //asm volatile("addi t0, x0, 55");

        /* asm volatile("csrw medeleg, t0");
         asm volatile("csrr t1, medeleg");
         asm volatile("li t0, 62");
         asm volatile("csrw mtvec, t0");
         asm volatile("csrr t0, mtvec");
        */
        
        //asm volatile("ecall");

        while (1) { asm volatile("wfi"); }
    }

    std::size_t getHartID()
    {
        std::size_t id;
        KTR_LOAD_CSR(mhartid, id, kt::riscv::regs::CSR_Op::eAtomic);
        return id;
    }
}