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
CMAKE_COMMAND = /home/hyreos/Documentos/git/CMake/bin/cmake

# The command to remove a file.
RM = /home/hyreos/Documentos/git/CMake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hyreos/Documentos/waifu-content

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hyreos/Documentos/waifu-content

# Include any dependencies generated for this target.
include kernel/CMakeFiles/kernel_core.dir/depend.make

# Include the progress variables for this target.
include kernel/CMakeFiles/kernel_core.dir/progress.make

# Include the compile flags for this target's objects.
include kernel/CMakeFiles/kernel_core.dir/flags.make

kernel/CMakeFiles/kernel_core.dir/utility.cpp.obj: kernel/CMakeFiles/kernel_core.dir/flags.make
kernel/CMakeFiles/kernel_core.dir/utility.cpp.obj: kernel/utility.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hyreos/Documentos/waifu-content/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object kernel/CMakeFiles/kernel_core.dir/utility.cpp.obj"
	cd /home/hyreos/Documentos/waifu-content/kernel && riscv64-unknown-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kernel_core.dir/utility.cpp.obj -c /home/hyreos/Documentos/waifu-content/kernel/utility.cpp

kernel/CMakeFiles/kernel_core.dir/utility.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kernel_core.dir/utility.cpp.i"
	cd /home/hyreos/Documentos/waifu-content/kernel && riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hyreos/Documentos/waifu-content/kernel/utility.cpp > CMakeFiles/kernel_core.dir/utility.cpp.i

kernel/CMakeFiles/kernel_core.dir/utility.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kernel_core.dir/utility.cpp.s"
	cd /home/hyreos/Documentos/waifu-content/kernel && riscv64-unknown-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hyreos/Documentos/waifu-content/kernel/utility.cpp -o CMakeFiles/kernel_core.dir/utility.cpp.s

# Object files for target kernel_core
kernel_core_OBJECTS = \
"CMakeFiles/kernel_core.dir/utility.cpp.obj"

# External object files for target kernel_core
kernel_core_EXTERNAL_OBJECTS =

kernel/libkernel_core.a: kernel/CMakeFiles/kernel_core.dir/utility.cpp.obj
kernel/libkernel_core.a: kernel/CMakeFiles/kernel_core.dir/build.make
kernel/libkernel_core.a: kernel/CMakeFiles/kernel_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hyreos/Documentos/waifu-content/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libkernel_core.a"
	cd /home/hyreos/Documentos/waifu-content/kernel && $(CMAKE_COMMAND) -P CMakeFiles/kernel_core.dir/cmake_clean_target.cmake
	cd /home/hyreos/Documentos/waifu-content/kernel && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kernel_core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
kernel/CMakeFiles/kernel_core.dir/build: kernel/libkernel_core.a

.PHONY : kernel/CMakeFiles/kernel_core.dir/build

kernel/CMakeFiles/kernel_core.dir/clean:
	cd /home/hyreos/Documentos/waifu-content/kernel && $(CMAKE_COMMAND) -P CMakeFiles/kernel_core.dir/cmake_clean.cmake
.PHONY : kernel/CMakeFiles/kernel_core.dir/clean

kernel/CMakeFiles/kernel_core.dir/depend:
	cd /home/hyreos/Documentos/waifu-content && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hyreos/Documentos/waifu-content /home/hyreos/Documentos/waifu-content/kernel /home/hyreos/Documentos/waifu-content /home/hyreos/Documentos/waifu-content/kernel /home/hyreos/Documentos/waifu-content/kernel/CMakeFiles/kernel_core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : kernel/CMakeFiles/kernel_core.dir/depend

