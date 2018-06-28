#include "1_0_0.h"

PUBLIC void start_gic() {
    // setup distributor
    io_writeoff32(A9_SCU_ADDRESS, GIC_DIS_OFFSSET + ICIO_D_CONTROL_REGISTER, ICDDCR_ENABLE_SECURE); // enable interrupt forwarding

    const uint32_t icdictr = io_readoff32(A9_SCU_ADDRESS, GIC_DIS_OFFSSET + ICIO_D_INTERRUPT_TYPE_REGISTER);
    const uint32_t max_intsrcs = icdictr & ICIO_SPI_LINE_NUMBER_BITMASK;
    const uint32_t cpu_number = (icdictr & A9_PROCESSOR_NUMBER_BITMASK);

    // setup GIC interface

    io_writeoff32(A9_SCU_ADDRESS, GIC_INT_OFFSSET + ICIO_I_PROCESSOR_INTERFACE_CONTROL_REGISTER, GIC_CONTROL_REGISTER_EBIT);
    io_writeoff32(A9_SCU_ADDRESS, GIC_INT_OFFSSET + ICIO_I_PRIORITY_MASK_REGISTER, ~0 && 0xFF);
}
