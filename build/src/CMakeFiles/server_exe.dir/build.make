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
include src/CMakeFiles/server_exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/server_exe.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/server_exe.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/server_exe.dir/flags.make

src/CMakeFiles/server_exe.dir/server.c.o: src/CMakeFiles/server_exe.dir/flags.make
src/CMakeFiles/server_exe.dir/server.c.o: /home/elias/udp_sockets/src/server.c
src/CMakeFiles/server_exe.dir/server.c.o: src/CMakeFiles/server_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/elias/udp_sockets/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/server_exe.dir/server.c.o"
	cd /home/elias/udp_sockets/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/server_exe.dir/server.c.o -MF CMakeFiles/server_exe.dir/server.c.o.d -o CMakeFiles/server_exe.dir/server.c.o -c /home/elias/udp_sockets/src/server.c

src/CMakeFiles/server_exe.dir/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/server_exe.dir/server.c.i"
	cd /home/elias/udp_sockets/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/elias/udp_sockets/src/server.c > CMakeFiles/server_exe.dir/server.c.i

src/CMakeFiles/server_exe.dir/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/server_exe.dir/server.c.s"
	cd /home/elias/udp_sockets/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/elias/udp_sockets/src/server.c -o CMakeFiles/server_exe.dir/server.c.s

# Object files for target server_exe
server_exe_OBJECTS = \
"CMakeFiles/server_exe.dir/server.c.o"

# External object files for target server_exe
server_exe_EXTERNAL_OBJECTS =

src/server_exe: src/CMakeFiles/server_exe.dir/server.c.o
src/server_exe: src/CMakeFiles/server_exe.dir/build.make
src/server_exe: lib/server/libserver.a
src/server_exe: lib/shared/libshared.a
src/server_exe: src/CMakeFiles/server_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/elias/udp_sockets/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable server_exe"
	cd /home/elias/udp_sockets/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/server_exe.dir/build: src/server_exe
.PHONY : src/CMakeFiles/server_exe.dir/build

src/CMakeFiles/server_exe.dir/clean:
	cd /home/elias/udp_sockets/build/src && $(CMAKE_COMMAND) -P CMakeFiles/server_exe.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/server_exe.dir/clean

src/CMakeFiles/server_exe.dir/depend:
	cd /home/elias/udp_sockets/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/elias/udp_sockets /home/elias/udp_sockets/src /home/elias/udp_sockets/build /home/elias/udp_sockets/build/src /home/elias/udp_sockets/build/src/CMakeFiles/server_exe.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/server_exe.dir/depend
