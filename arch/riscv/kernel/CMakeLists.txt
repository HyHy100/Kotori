add_library(rvarch_kernel)

target_sources(rvarch_kernel
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/pcb.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tcb.cpp
)