add_library(chardev)

target_sources(chardev
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/uart.cpp
)