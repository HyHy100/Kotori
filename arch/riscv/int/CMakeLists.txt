add_library(arch_riscv_int)

target_sources(arch_riscv_int
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inte.cpp
)