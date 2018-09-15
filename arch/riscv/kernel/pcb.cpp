#include "pcb.hpp"

namespace kt::sched {
    PCB::PCB()
    {
    }

    PCB::id_t PCB::id() const
    {
        return pid;
    }

    PCB* PCB::next() const
    {
        return pNext;
    }
}