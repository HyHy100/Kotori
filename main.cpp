#include "arch/riscv/proc.hpp"
#include "arch/riscv/sifive/serial.hpp"
#include "arch/riscv/dri/console/spike/htif.hpp"
#include "kernel/utility.hpp"

asm volatile("jal _start");

extern "C" void krnl()
{	
	kt::riscv::proc::archKernelStart();
	
	while (1) { asm volatile("nop"); }
}
