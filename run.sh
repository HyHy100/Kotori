#!/bin/bash

if [ "$1" == "spike" ]; then
    spike bin/kotori.elf
else
    qemu-system-riscv64  -machine spike_v1.9.1 -nographic -kernel bin/kotori.elf 
fi
