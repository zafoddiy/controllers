# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/elias/udp_sockets

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/elias/udp_sockets/build

# Include any dependencies generated for this target.
include src/CMakeFiles/cooling.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/cooling.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/cooling.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/cooling.dir/flags.make

src/CMakeFiles/cooling.dir/cooling.c.o: src/CMakeFiles/cooling.dir/flags.make
src/CMakeFiles/cooling.dir/cooling.c.o: /home/elias/udp_sockets/src/cooling.c
src/CMakeFiles/cooling.dir/cooling.c.o: src/CMakeFiles/cooling.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/elias/udp_sockets/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/cooling.dir/cooling.c.o"
	cd /home/elias/udp_sockets/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/cooling.dir/cooling.c.o -MF CMakeFiles/cooling.dir/cooling.c.o.d -o CMakeFiles/cooling.dir/cooling.c.o -c /home/elias/udp_sockets/src/cooling.c

src/CMakeFiles/cooling.dir/cooling.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/cooling.dir/cooling.c.i"
	cd /home/elias/udp_sockets/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/elias/udp_sockets/src/cooling.c > CMakeFiles/cooling.dir/cooling.c.i

src/CMakeFiles/cooling.dir/cooling.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/cooling.dir/cooling.c.s"
	cd /home/elias/udp_sockets/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/elias/udp_sockets/src/cooling.c -o CMakeFiles/cooling.dir/cooling.c.s

# Object files for target cooling
cooling_OBJECTS = \
"CMakeFiles/cooling.dir/cooling.c.o"

# External object files for target cooling
cooling_EXTERNAL_OBJECTS =

src/cooling: src/CMakeFiles/cooling.dir/cooling.c.o
src/cooling: src/CMakeFiles/cooling.dir/build.make
src/cooling: lib/controllers/libcontrollers.a
src/cooling: lib/shared/libshared.a
src/cooling: src/CMakeFiles/cooling.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/elias/udp_sockets/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cooling"
	cd /home/elias/udp_sockets/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cooling.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/cooling.dir/build: src/cooling
.PHONY : src/CMakeFiles/cooling.dir/build

src/CMakeFiles/cooling.dir/clean:
	cd /home/elias/udp_sockets/build/src && $(CMAKE_COMMAND) -P CMakeFiles/cooling.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/cooling.dir/clean

src/CMakeFiles/cooling.dir/depend:
	cd /home/elias/udp_sockets/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/elias/udp_sockets /home/elias/udp_sockets/src /home/elias/udp_sockets/build /home/elias/udp_sockets/build/src /home/elias/udp_sockets/build/src/CMakeFiles/cooling.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/cooling.dir/depend

