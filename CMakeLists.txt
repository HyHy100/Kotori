cmake_minimum_required(VERSION 3.12)

project(kotori CXX C ASM)

set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}-g++)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}-as)

add_executable(kotori main.cpp startup.S)

set(CMAKE_CXX_FLAGS "-march=rv64imac -mabi=lp64 -static -std=c++17 -Os -ffunction-sections -nostartfiles -fpermissive -mcmodel=medany -fno-exceptions -Tlinker.ld")
set(CMAKE_ASM_FLAGS "-march=rv64imac -mabi=lp64")

set(EXECUTABLE_OUTPUT_PATH bin)
set_target_properties(kotori PROPERTIES OUTPUT_NAME kotori)
set_target_properties(kotori PROPERTIES SUFFIX .elf)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(kernel)
add_subdirectory(arch)

target_link_libraries(kotori
                    rvarch # arch dependent code
                    arch_riscv_timers # risc-v timers
                    rvarch_sifive # risc-v sifive drivers
                    rvarch_kernel # risc-v kernel
                    arch_riscv_int # risc-v interrupts
                    kernel_core # arch independent kernel code
                    chardev # character devices
                    arch_riscv_spike_htif # spike htif interface
                )
