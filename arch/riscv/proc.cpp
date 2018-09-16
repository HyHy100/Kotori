#include "proc.hpp"
#include "trap.h"
#include "sifive/serial.hpp"
#include "regs.hpp"
#include "timer/rtc.hpp"

#include <ktl/memory.hpp>
#include "../../kernel/utility.hpp"
#include "vm/vm.hpp"
#include "int/inte.hpp"

#include "../../term/colors.hpp"
#include "dri/console/spike/htif.hpp"

                                                                                                
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
        spike::Htif::init();

        setTrapVector(inte::trapVectorHandler);
        inte::enaint();
        
        //delegateExceptions();
        
        constexpr auto printSeparator = [] {
            aux::console << ANSI_COLOR_YELLOW"|\n|\n";
        };

        aux::console << (
            #include "weeb.hpp"
        );

        aux::console << ANSI_COLOR_BLUE "[K]" ANSI_COLOR_MAGENTA "otori: a weeaboo embedded kernel. o//o\n" ANSI_COLOR_RESET;
        aux::console << ANSI_COLOR_YELLOW"Collecting CPU information... \n";

        aux::console << ANSI_COLOR_BLUE"-- Arch:" ANSI_COLOR_RED " RISC-V\n" ANSI_COLOR_RESET;
        printSeparator();
        
        machineInfo = queryCPUInformation();
        
        aux::console << ANSI_COLOR_YELLOW"Info:\n";

        printSeparator();
        aux::console << ANSI_COLOR_BLUE"-- ISA width: ";

        if (machineInfo.isawidth == 32) {
            aux::console << ANSI_COLOR_RED"32";
        } else if (machineInfo.isawidth == 64) {
            aux::console << ANSI_COLOR_RED"64";
        } else {
            aux::console << ANSI_COLOR_RED"128";
        }

        aux::console << ANSI_COLOR_YELLOW" - Ok!\n"ANSI_COLOR_RESET;

        printSeparator();

        aux::console << "Setting up trap handler...\n";

        aux::console << "Ok!\n";

        sifive::init();

        aux::console << "Initializing rtc timers... \n";

        timers::rtcTimerInit();

        aux::console << "Ok!\n";

        vm::initMemory();

        while (1) { asm volatile("wfi"); }
    }

    std::size_t getHartID()
    {
        std::size_t id;
        KTR_LOAD_CSR(mhartid, id, kt::riscv::regs::CSR_Op::eAtomic);
        return id;
    }
}