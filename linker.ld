OUTPUT_ARCH( "riscv" )
ENTRY( startEnvironment )
SECTIONS
{
  . = 0x80000000;
  .text : { 
    *(.start)
    *(.text)
  }
  /* data: Initialized data segment */
  .data : { *(.data) }
  .rodata : { *(.rodata) }
  .sdata : { *(.sdata) }
  .htif : {
    . = ALIGN(8); 
    *(.htif)
  }

  .debug : { *(.debug) }

  . = ALIGN(4);
  kernelHeap = .;
  . += 0x20000000;
  . = ALIGN(4);
  kernelStack = .;

  /* End of uninitalized data segement */
  _end = .;
}