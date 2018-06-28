/*
    GIC v1.0
*/


#if !defined(_GICH_)
#define _GICH_

#include <stdint.h>
#include "../../../utils/gendef.h"

#define PUBLIC
#define PRIVATE static

/*
    Interrupt Controller Interface offset from PERIPHBASE
    Interrupt Distributor Offset from PERIPHBASE
*/
#define GIC_INT_OFFSSET             0x0100
#define GIC_DIS_OFFSSET             0x1000

/*
    This bit enable interrupts
*/
#define GIC_CONTROL_REGISTER_EBIT   0x1

#define ICDDCR_ENABLE_SECURE        0x2
#define ICDDCR_ENABLE_NON_SECURE    0x1

/*
    The Distributor in the GIC can handle 255 sources of interrupt
    Sources from 0 to 31 are used for PPIs(Private Peripherals Interrupts) but Sources from 0 to 15 are used for software interrupts... I think?
    Sources from 32 to 255 are used for SPIs(Shared Peripherals Interrupts)
*/

#define SW_INTERRUPT0  0x0
#define SW_INTERRUPT1  0x1
#define SW_INTERRUPT2  0x2
#define SW_INTERRUPT3  0x3
#define SW_INTERRUPT4  0x4
#define SW_INTERRUPT5  0x5
#define SW_INTERRUPT6  0x6
#define SW_INTERRUPT7  0x7
#define SW_INTERRUPT8  0x8
#define SW_INTERRUPT9  0x9
#define SW_INTERRUPT10 0xA
#define SW_INTERRUPT11 0xB
#define SW_INTERRUPT12 0xC
#define SW_INTERRUPT13 0xD
#define SW_INTERRUPT14 0xE
#define SW_INTERRUPT15 0xF

typedef uint32_t int_id_t;

/*
    Distributor mmap
*/

#define ICIO_D_CONTROL_REGISTER                       0x000
#define ICIO_D_INTERRUPT_TYPE_REGISTER                0x004
#define ICIO_D_IMPLEMENT_ID_REGISTER                  0x008

#define ICIO_D_INTERRUPT_SECURITY_REGISTERS           0x80
#define ICIO_D_ENABLE_SET_REGISTERS                   0x100
#define ICIO_D_ENABLE_CLEAR_REGISTERS                 0x180
#define ICIO_D_PENDING_SET_REGISTERS                  0x200
#define ICIO_D_PENDING_CLEAR_REGISTERS                0x280
#define ICIO_D_ACTIVE_STATUS_REGISTERS                0x300
#define ICIO_D_PRIORITY_LEVEL_REGISTERS               0x400
#define ICIO_D_SPI_TARGET_REGISTERS                   0x800
#define ICIO_D_PPI_STATUS_REGISTER                    0xC00
#define ICIO_D_SPI_STATUS_REGISTER                    0xD00
#define ICIO_D_SOFTWARE_GENERATED_INTERRUPT_REGISTER  0xD04
#define ICIO_D_PERIPH_IDENTIFICATION_REGISTER         0xF00

/*
    CPU Interface mmap
*/

#define ICIO_I_PROCESSOR_INTERFACE_CONTROL_REGISTER   0x000
#define ICIO_I_PRIORITY_MASK_REGISTER                 0x004
#define ICIO_I_BINARY_POINT_REGISTER                  0x008
#define ICIO_I_INTERRUPT_ACNOWLEDGE_REGISTER          0x00C
#define ICIO_I_END_OF_INTERRUPT_REGISTER              0x010
#define ICIO_I_RUNNING_PRIORITY_REGISTER              0x014
#define ICIO_I_HIGHEST_PENDING_INTERRUPT_REGISTER     0x018
#define ICIO_I_ALIASED_NONSECURE_BINARY_POINT_REGISTER 0x01C
#define ICIO_I_PROCESSOR_INT_IMPLEMENTER_ID_REGISTER  0xFC


/*
    These bits determines the CPU number
*/

#define A9_PROCESSOR_NUMBER_BITMASK                 (0x7 << 0x5)
#define A9_PROCESSOR_ONE                            (0x0 << 0x5)
#define A9_PROCESSOR_TWO                            (0x4 << 0x5)
#define A9_PROCESSOR_THREE                          (0x2 << 0x5)
#define A9_PROCESSOR_FOUR                           (0x6 << 0x5)

#define ICIO_SPI_LINE_NUMBER_BITMASK                0x1F
#define ICIO_SPI_LINE_NUMBER_32                     0x0
#define ICIO_SPI_LINE_NUMBER_64                     0x1
#define ICIO_SPI_LINE_NUMBER_96                     0x2
#define ICIO_SPI_LINE_NUMBER_128                    0x3
#define ICIO_SPI_LINE_NUMBER_160                    0x4
#define ICIO_SPI_LINE_NUMBER_192                    0x5
#define ICIO_SPI_LINE_NUMBER_224                    0x6
#define ICIO_SPI_LINE_NUMBER_256                    0x7

#define A9_SCU_ADDRESS ((uint8_t*)0x1e000000)

PUBLIC _FORCED_INLINE void disable_interrupts() {
    __asm__ volatile("cpsid I");
    io_writeoff32(A9_SCU_ADDRESS, GIC_INT_OFFSSET + ICIO_I_PROCESSOR_INTERFACE_CONTROL_REGISTER, 0x0);
}

PUBLIC _FORCED_INLINE void enable_interrupts() {
    __asm__ volatile("cpsie I");
    io_writeoff32(A9_SCU_ADDRESS, GIC_INT_OFFSSET + ICIO_I_PROCESSOR_INTERFACE_CONTROL_REGISTER, GIC_CONTROL_REGISTER_EBIT);
}

PUBLIC void start_gic();

#endif
