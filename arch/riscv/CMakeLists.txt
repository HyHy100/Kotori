add_library(rvarch)

add_subdirectory(kernel)
add_subdirectory(sifive)
add_subdirectory(timer)
add_subdirectory(int)
add_subdirectory(dri)

target_sources(rvarch
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/proc.cpp
)