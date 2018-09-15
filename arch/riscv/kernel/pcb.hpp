#pragma once

#include "tcb.hpp"

#include <ktl/list/single.hpp>

namespace kt::sched {
    class PCB {
    public:
        using id_t = long long;

        PCB();

        id_t id() const;

        PCB* next() const;
    private:
        id_t pid;

        ktl::SingleList<TCB> threadList;
        PCB* currentThread;

        PCB* pNext;
    };
}