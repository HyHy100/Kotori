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
include CMakeFiles/Kotori.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Kotori.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Kotori.dir/flags.make

CMakeFiles/Kotori.dir/main.cpp.obj: CMakeFiles/Kotori.dir/flags.make
CMakeFiles/Kotori.dir/main.cpp.obj: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/hyreos/Documentos/waifu content/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Kotori.dir/main.cpp.obj"
	riscv64-unknown-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Kotori.dir/main.cpp.obj -c "/home/hyreos/Documentos/waifu content/main.cpp"

CMakeFiles/Kotori.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kotori.dir/main.cpp.i"
	riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/hyreos/Documentos/waifu content/main.cpp" > CMakeFiles/Kotori.dir/main.cpp.i

CMakeFiles/Kotori.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kotori.dir/main.cpp.s"
	riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/hyreos/Documentos/waifu content/main.cpp" -o CMakeFiles/Kotori.dir/main.cpp.s

CMakeFiles/Kotori.dir/startup.S.obj: CMakeFiles/Kotori.dir/flags.make
CMakeFiles/Kotori.dir/startup.S.obj: startup.S
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/hyreos/Documentos/waifu content/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building ASM object CMakeFiles/Kotori.dir/startup.S.obj"
	riscv64-unknown-elf-as $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/Kotori.dir/startup.S.obj -c "/home/hyreos/Documentos/waifu content/startup.S"

CMakeFiles/Kotori.dir/kernel/chardev/uart.cpp.obj: CMakeFiles/Kotori.dir/flags.make
CMakeFiles/Kotori.dir/kernel/chardev/uart.cpp.obj: kernel/chardev/uart.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/hyreos/Documentos/waifu content/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Kotori.dir/kernel/chardev/uart.cpp.obj"
	riscv64-unknown-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Kotori.dir/kernel/chardev/uart.cpp.obj -c "/home/hyreos/Documentos/waifu content/kernel/chardev/uart.cpp"

CMakeFiles/Kotori.dir/kernel/chardev/uart.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kotori.dir/kernel/chardev/uart.cpp.i"
	riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/hyreos/Documentos/waifu content/kernel/chardev/uart.cpp" > CMakeFiles/Kotori.dir/kernel/chardev/uart.cpp.i

CMakeFiles/Kotori.dir/kernel/chardev/uart.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kotori.dir/kernel/chardev/uart.cpp.s"
	riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/hyreos/Documentos/waifu content/kernel/chardev/uart.cpp" -o CMakeFiles/Kotori.dir/kernel/chardev/uart.cpp.s

CMakeFiles/Kotori.dir/arch/riscv/kernel/pcb.cpp.obj: CMakeFiles/Kotori.dir/flags.make
CMakeFiles/Kotori.dir/arch/riscv/kernel/pcb.cpp.obj: arch/riscv/kernel/pcb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/hyreos/Documentos/waifu content/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Kotori.dir/arch/riscv/kernel/pcb.cpp.obj"
	riscv64-unknown-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Kotori.dir/arch/riscv/kernel/pcb.cpp.obj -c "/home/hyreos/Documentos/waifu content/arch/riscv/kernel/pcb.cpp"

CMakeFiles/Kotori.dir/arch/riscv/kernel/pcb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kotori.dir/arch/riscv/kernel/pcb.cpp.i"
	riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/hyreos/Documentos/waifu content/arch/riscv/kernel/pcb.cpp" > CMakeFiles/Kotori.dir/arch/riscv/kernel/pcb.cpp.i

CMakeFiles/Kotori.dir/arch/riscv/kernel/pcb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kotori.dir/arch/riscv/kernel/pcb.cpp.s"
	riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/hyreos/Documentos/waifu content/arch/riscv/kernel/pcb.cpp" -o CMakeFiles/Kotori.dir/arch/riscv/kernel/pcb.cpp.s

CMakeFiles/Kotori.dir/arch/riscv/kernel/tcb.cpp.obj: CMakeFiles/Kotori.dir/flags.make
CMakeFiles/Kotori.dir/arch/riscv/kernel/tcb.cpp.obj: arch/riscv/kernel/tcb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/hyreos/Documentos/waifu content/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Kotori.dir/arch/riscv/kernel/tcb.cpp.obj"
	riscv64-unknown-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Kotori.dir/arch/riscv/kernel/tcb.cpp.obj -c "/home/hyreos/Documentos/waifu content/arch/riscv/kernel/tcb.cpp"

CMakeFiles/Kotori.dir/arch/riscv/kernel/tcb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kotori.dir/arch/riscv/kernel/tcb.cpp.i"
	riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/hyreos/Documentos/waifu content/arch/riscv/kernel/tcb.cpp" > CMakeFiles/Kotori.dir/arch/riscv/kernel/tcb.cpp.i

CMakeFiles/Kotori.dir/arch/riscv/kernel/tcb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kotori.dir/arch/riscv/kernel/tcb.cpp.s"
	riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/hyreos/Documentos/waifu content/arch/riscv/kernel/tcb.cpp" -o CMakeFiles/Kotori.dir/arch/riscv/kernel/tcb.cpp.s

CMakeFiles/Kotori.dir/arch/riscv/proc.cpp.obj: CMakeFiles/Kotori.dir/flags.make
CMakeFiles/Kotori.dir/arch/riscv/proc.cpp.obj: arch/riscv/proc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/hyreos/Documentos/waifu content/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Kotori.dir/arch/riscv/proc.cpp.obj"
	riscv64-unknown-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Kotori.dir/arch/riscv/proc.cpp.obj -c "/home/hyreos/Documentos/waifu content/arch/riscv/proc.cpp"

CMakeFiles/Kotori.dir/arch/riscv/proc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kotori.dir/arch/riscv/proc.cpp.i"
	riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/hyreos/Documentos/waifu content/arch/riscv/proc.cpp" > CMakeFiles/Kotori.dir/arch/riscv/proc.cpp.i

CMakeFiles/Kotori.dir/arch/riscv/proc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kotori.dir/arch/riscv/proc.cpp.s"
	riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/hyreos/Documentos/waifu content/arch/riscv/proc.cpp" -o CMakeFiles/Kotori.dir/arch/riscv/proc.cpp.s

CMakeFiles/Kotori.dir/arch/riscv/sifive/serial.cpp.obj: CMakeFiles/Kotori.dir/flags.make
CMakeFiles/Kotori.dir/arch/riscv/sifive/serial.cpp.obj: arch/riscv/sifive/serial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/hyreos/Documentos/waifu content/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Kotori.dir/arch/riscv/sifive/serial.cpp.obj"
	riscv64-unknown-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Kotori.dir/arch/riscv/sifive/serial.cpp.obj -c "/home/hyreos/Documentos/waifu content/arch/riscv/sifive/serial.cpp"

CMakeFiles/Kotori.dir/arch/riscv/sifive/serial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kotori.dir/arch/riscv/sifive/serial.cpp.i"
	riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/hyreos/Documentos/waifu content/arch/riscv/sifive/serial.cpp" > CMakeFiles/Kotori.dir/arch/riscv/sifive/serial.cpp.i

CMakeFiles/Kotori.dir/arch/riscv/sifive/serial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kotori.dir/arch/riscv/sifive/serial.cpp.s"
	riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/hyreos/Documentos/waifu content/arch/riscv/sifive/serial.cpp" -o CMakeFiles/Kotori.dir/arch/riscv/sifive/serial.cpp.s

# Object files for target Kotori
Kotori_OBJECTS = \
"CMakeFiles/Kotori.dir/main.cpp.obj" \
"CMakeFiles/Kotori.dir/startup.S.obj" \
"CMakeFiles/Kotori.dir/kernel/chardev/uart.cpp.obj" \
"CMakeFiles/Kotori.dir/arch/riscv/kernel/pcb.cpp.obj" \
"CMakeFiles/Kotori.dir/arch/riscv/kernel/tcb.cpp.obj" \
"CMakeFiles/Kotori.dir/arch/riscv/proc.cpp.obj" \
"CMakeFiles/Kotori.dir/arch/riscv/sifive/serial.cpp.obj"

# External object files for target Kotori
Kotori_EXTERNAL_OBJECTS =

bin/kotori.elf: CMakeFiles/Kotori.dir/main.cpp.obj
bin/kotori.elf: CMakeFiles/Kotori.dir/startup.S.obj
bin/kotori.elf: CMakeFiles/Kotori.dir/kernel/chardev/uart.cpp.obj
bin/kotori.elf: CMakeFiles/Kotori.dir/arch/riscv/kernel/pcb.cpp.obj
bin/kotori.elf: CMakeFiles/Kotori.dir/arch/riscv/kernel/tcb.cpp.obj
bin/kotori.elf: CMakeFiles/Kotori.dir/arch/riscv/proc.cpp.obj
bin/kotori.elf: CMakeFiles/Kotori.dir/arch/riscv/sifive/serial.cpp.obj
bin/kotori.elf: CMakeFiles/Kotori.dir/build.make
bin/kotori.elf: kernel/chardev/libCharDev.a
bin/kotori.elf: arch/riscv/kernel/libRISCV_Arch_Kernel.a
bin/kotori.elf: arch/riscv/libRISCV_Arch.a
bin/kotori.elf: arch/riscv/sifive/libArchRISCVSifive.a
bin/kotori.elf: CMakeFiles/Kotori.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/hyreos/Documentos/waifu content/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable bin/kotori.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Kotori.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Kotori.dir/build: bin/kotori.elf

.PHONY : CMakeFiles/Kotori.dir/build

CMakeFiles/Kotori.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Kotori.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Kotori.dir/clean

CMakeFiles/Kotori.dir/depend:
	cd "/home/hyreos/Documentos/waifu content" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/hyreos/Documentos/waifu content" "/home/hyreos/Documentos/waifu content" "/home/hyreos/Documentos/waifu content" "/home/hyreos/Documentos/waifu content" "/home/hyreos/Documentos/waifu content/CMakeFiles/Kotori.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Kotori.dir/depend

