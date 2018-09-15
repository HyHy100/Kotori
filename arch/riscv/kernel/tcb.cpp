#include "tcb.hpp"
#include "pcb.hpp"

namespace kt::sched {
    Context::Context(bool isDirty)
        : fdirty(isDirty)
    {
    }

    PCB& TCB::parent()
    {
        return parentRef;
    }
}
