# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/hyreos/Documentos/waifu content"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/hyreos/Documentos/waifu content"

# Include any dependencies generated for this target.
include arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/depend.make

# Include the progress variables for this target.
include arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/progress.make

# Include the compile flags for this target's objects.
include arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/flags.make

arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/pcb.cpp.obj: arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/flags.make
arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/pcb.cpp.obj: arch/riscv/kernel/pcb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/hyreos/Documentos/waifu content/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/pcb.cpp.obj"
	cd "/home/hyreos/Documentos/waifu content/arch/riscv/kernel" && riscv64-unknown-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RISCV_ARCH_KERNEL.dir/pcb.cpp.obj -c "/home/hyreos/Documentos/waifu content/arch/riscv/kernel/pcb.cpp"

arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/pcb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RISCV_ARCH_KERNEL.dir/pcb.cpp.i"
	cd "/home/hyreos/Documentos/waifu content/arch/riscv/kernel" && riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/hyreos/Documentos/waifu content/arch/riscv/kernel/pcb.cpp" > CMakeFiles/RISCV_ARCH_KERNEL.dir/pcb.cpp.i

arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/pcb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RISCV_ARCH_KERNEL.dir/pcb.cpp.s"
	cd "/home/hyreos/Documentos/waifu content/arch/riscv/kernel" && riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/hyreos/Documentos/waifu content/arch/riscv/kernel/pcb.cpp" -o CMakeFiles/RISCV_ARCH_KERNEL.dir/pcb.cpp.s

arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/tcb.cpp.obj: arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/flags.make
arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/tcb.cpp.obj: arch/riscv/kernel/tcb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/hyreos/Documentos/waifu content/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/tcb.cpp.obj"
	cd "/home/hyreos/Documentos/waifu content/arch/riscv/kernel" && riscv64-unknown-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RISCV_ARCH_KERNEL.dir/tcb.cpp.obj -c "/home/hyreos/Documentos/waifu content/arch/riscv/kernel/tcb.cpp"

arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/tcb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RISCV_ARCH_KERNEL.dir/tcb.cpp.i"
	cd "/home/hyreos/Documentos/waifu content/arch/riscv/kernel" && riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/hyreos/Documentos/waifu content/arch/riscv/kernel/tcb.cpp" > CMakeFiles/RISCV_ARCH_KERNEL.dir/tcb.cpp.i

arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/tcb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RISCV_ARCH_KERNEL.dir/tcb.cpp.s"
	cd "/home/hyreos/Documentos/waifu content/arch/riscv/kernel" && riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/hyreos/Documentos/waifu content/arch/riscv/kernel/tcb.cpp" -o CMakeFiles/RISCV_ARCH_KERNEL.dir/tcb.cpp.s

# Object files for target RISCV_ARCH_KERNEL
RISCV_ARCH_KERNEL_OBJECTS = \
"CMakeFiles/RISCV_ARCH_KERNEL.dir/pcb.cpp.obj" \
"CMakeFiles/RISCV_ARCH_KERNEL.dir/tcb.cpp.obj"

# External object files for target RISCV_ARCH_KERNEL
RISCV_ARCH_KERNEL_EXTERNAL_OBJECTS =

arch/riscv/kernel/libRISCV_ARCH_KERNEL.a: arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/pcb.cpp.obj
arch/riscv/kernel/libRISCV_ARCH_KERNEL.a: arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/tcb.cpp.obj
arch/riscv/kernel/libRISCV_ARCH_KERNEL.a: arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/build.make
arch/riscv/kernel/libRISCV_ARCH_KERNEL.a: arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/hyreos/Documentos/waifu content/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libRISCV_ARCH_KERNEL.a"
	cd "/home/hyreos/Documentos/waifu content/arch/riscv/kernel" && $(CMAKE_COMMAND) -P CMakeFiles/RISCV_ARCH_KERNEL.dir/cmake_clean_target.cmake
	cd "/home/hyreos/Documentos/waifu content/arch/riscv/kernel" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RISCV_ARCH_KERNEL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/build: arch/riscv/kernel/libRISCV_ARCH_KERNEL.a

.PHONY : arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/build

arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/clean:
	cd "/home/hyreos/Documentos/waifu content/arch/riscv/kernel" && $(CMAKE_COMMAND) -P CMakeFiles/RISCV_ARCH_KERNEL.dir/cmake_clean.cmake
.PHONY : arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/clean

arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/depend:
	cd "/home/hyreos/Documentos/waifu content" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/hyreos/Documentos/waifu content" "/home/hyreos/Documentos/waifu content/arch/riscv/kernel" "/home/hyreos/Documentos/waifu content" "/home/hyreos/Documentos/waifu content/arch/riscv/kernel" "/home/hyreos/Documentos/waifu content/arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : arch/riscv/kernel/CMakeFiles/RISCV_ARCH_KERNEL.dir/depend

