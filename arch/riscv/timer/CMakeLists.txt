add_library(arch_riscv_timers)

target_sources(arch_riscv_timers
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/rtc.cpp
)