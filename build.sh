#!/bin/bash

cmake . -DTOOLCHAIN_PREFIX="riscv64-unknown-elf" -DCMAKE_TOOLCHAIN_FILE=cross-riscv.cmake
make ARCH=riscv V=1