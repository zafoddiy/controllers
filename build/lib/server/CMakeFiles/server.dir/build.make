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
include lib/server/CMakeFiles/server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/server/CMakeFiles/server.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/server/CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include lib/server/CMakeFiles/server.dir/flags.make

lib/server/CMakeFiles/server.dir/processing.c.o: lib/server/CMakeFiles/server.dir/flags.make
lib/server/CMakeFiles/server.dir/processing.c.o: /home/elias/udp_sockets/lib/server/processing.c
lib/server/CMakeFiles/server.dir/processing.c.o: lib/server/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/elias/udp_sockets/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/server/CMakeFiles/server.dir/processing.c.o"
	cd /home/elias/udp_sockets/build/lib/server && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/server/CMakeFiles/server.dir/processing.c.o -MF CMakeFiles/server.dir/processing.c.o.d -o CMakeFiles/server.dir/processing.c.o -c /home/elias/udp_sockets/lib/server/processing.c

lib/server/CMakeFiles/server.dir/processing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/server.dir/processing.c.i"
	cd /home/elias/udp_sockets/build/lib/server && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/elias/udp_sockets/lib/server/processing.c > CMakeFiles/server.dir/processing.c.i

lib/server/CMakeFiles/server.dir/processing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/server.dir/processing.c.s"
	cd /home/elias/udp_sockets/build/lib/server && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/elias/udp_sockets/lib/server/processing.c -o CMakeFiles/server.dir/processing.c.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/processing.c.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

lib/server/libserver.a: lib/server/CMakeFiles/server.dir/processing.c.o
lib/server/libserver.a: lib/server/CMakeFiles/server.dir/build.make
lib/server/libserver.a: lib/server/CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/elias/udp_sockets/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libserver.a"
	cd /home/elias/udp_sockets/build/lib/server && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean_target.cmake
	cd /home/elias/udp_sockets/build/lib/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/server/CMakeFiles/server.dir/build: lib/server/libserver.a
.PHONY : lib/server/CMakeFiles/server.dir/build

lib/server/CMakeFiles/server.dir/clean:
	cd /home/elias/udp_sockets/build/lib/server && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : lib/server/CMakeFiles/server.dir/clean

lib/server/CMakeFiles/server.dir/depend:
	cd /home/elias/udp_sockets/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/elias/udp_sockets /home/elias/udp_sockets/lib/server /home/elias/udp_sockets/build /home/elias/udp_sockets/build/lib/server /home/elias/udp_sockets/build/lib/server/CMakeFiles/server.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/server/CMakeFiles/server.dir/depend

