#!/bin/bash

if [ "$1" == "qemu" ]; then
    qemu-system-riscv64  -machine spike_v1.9.1 -nographic -kernel bin/kotori.elf 
else
    spike bin/kotori.elf
fi
