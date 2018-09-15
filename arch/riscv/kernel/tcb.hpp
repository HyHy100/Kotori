#pragma once

#include <cstdint>

namespace kt::sched {
    /********************************
        Used for save thread state
    *********************************/
    class PCB;

    class Context {
    public:
        Context(bool isDirty);

        ~Context() = default;

        bool fdirty;

        volatile std::size_t ra, sp, gp, tp;
        volatile std::size_t t0, t1, t2;
        volatile std::size_t s0, s1;
        volatile std::size_t s2, s3, s4, s5, s6, s7, s8, s9, s10, s11;
        volatile std::size_t t3, t4, t5, t6;

        volatile std::size_t ft0, ft1, ft2, ft3, ft4, ft5, ft6, ft7;
        volatile std::size_t fs0, fs1;
        volatile std::size_t fa0, fa1, fa2, fa3, fa4, fa5, fa6, fa7;
        volatile std::size_t fs2, fs3, fs4, fs5, fs6, fs7, fs8, fs9, fs10, fs11;
        volatile std::size_t ft8, ft9, ft10, ft11;
    };

    class TCB {
    public:
        TCB() = delete;

        TCB(const PCB& parent);

        ~TCB() = default;

        PCB& parent();
    private:
        Context context;
        PCB& parentRef;
    };
}