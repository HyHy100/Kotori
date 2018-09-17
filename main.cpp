#include "arch/riscv/proc.hpp"
#include "arch/riscv/sifive/serial.hpp"
#include "arch/riscv/dri/console/spike/htif.hpp"
#include "kernel/utility.hpp"

extern "C" void krnl()
{
	while (true) { asm volatile("nop"); }
}