add_library(arch_riscv_spike_htif)

target_sources(arch_riscv_spike_htif
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/htif.cpp
)