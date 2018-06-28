cmake_minimum_required(VERSION 3.10)

project(HyreOS C ASM)

set(OUT_RDIR bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${OUT_RDIR})

set(LINKER_FILE "linker.ld")

set(KERNEL_FILES    kernel.c
                    irq.c
                    utils/io.c
)

set(ARCH_FILES      arch/arm/start.s
                    arch/arm/gic/1_0_0.c
)

set(DRI_FILES       dri/video/pl111/pl111.c
                    dri/serial/serial.c
                    dri/serial/uart/pl011.c
)

set(COMMON_SOURCES  ${KERNEL_FILES}
                    ${ARCH_FILES}
                    ${DRI_FILES}
)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-as)

set(CMAKE_EXE_LINKER_FLAGS "-T${LINKER_FILE} -static")

set(CPU_TARGET "cortex-a9")


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=${CPU_TARGET} -nostdlib -static -g")
set(CMAKE_ASM_FLAGS "${CFLAGS}")

set(OUT_FILE ${PROJECT_NAME}.elf)

add_executable(${OUT_FILE} ${COMMON_SOURCES})

set(QEMU_EXECUTABLE qemu-system-arm)
set(QEMU_ARGS -M vexpress-a9 -smp 4 -s -m 256 -kernel ${OUT_RDIR}/${OUT_FILE} -append "console=ttyAMA0,115200 root=/dev/mmcblk0" -serial stdio -net nic -net user)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD COMMAND ${QEMU_EXECUTABLE} ${QEMU_ARGS} COMMENT "Starting QemuARM...")
