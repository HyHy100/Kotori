add_library(kernel_core)

add_subdirectory(chardev)

target_sources(kernel_core
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/utility.cpp)