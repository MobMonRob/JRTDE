# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mosab/Schreibtisch/RTDE/ur_rtde

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mosab/Schreibtisch/RTDE/ur_rtde/build

# Include any dependencies generated for this target.
include CMakeFiles/servoj_example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/servoj_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/servoj_example.dir/flags.make

CMakeFiles/servoj_example.dir/examples/cpp/servoj_example.cpp.o: CMakeFiles/servoj_example.dir/flags.make
CMakeFiles/servoj_example.dir/examples/cpp/servoj_example.cpp.o: ../examples/cpp/servoj_example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mosab/Schreibtisch/RTDE/ur_rtde/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/servoj_example.dir/examples/cpp/servoj_example.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servoj_example.dir/examples/cpp/servoj_example.cpp.o -c /home/mosab/Schreibtisch/RTDE/ur_rtde/examples/cpp/servoj_example.cpp

CMakeFiles/servoj_example.dir/examples/cpp/servoj_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servoj_example.dir/examples/cpp/servoj_example.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mosab/Schreibtisch/RTDE/ur_rtde/examples/cpp/servoj_example.cpp > CMakeFiles/servoj_example.dir/examples/cpp/servoj_example.cpp.i

CMakeFiles/servoj_example.dir/examples/cpp/servoj_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servoj_example.dir/examples/cpp/servoj_example.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mosab/Schreibtisch/RTDE/ur_rtde/examples/cpp/servoj_example.cpp -o CMakeFiles/servoj_example.dir/examples/cpp/servoj_example.cpp.s

# Object files for target servoj_example
servoj_example_OBJECTS = \
"CMakeFiles/servoj_example.dir/examples/cpp/servoj_example.cpp.o"

# External object files for target servoj_example
servoj_example_EXTERNAL_OBJECTS =

../bin/servoj_example: CMakeFiles/servoj_example.dir/examples/cpp/servoj_example.cpp.o
../bin/servoj_example: CMakeFiles/servoj_example.dir/build.make
../bin/servoj_example: librtde.so.1.3.2
../bin/servoj_example: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
../bin/servoj_example: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
../bin/servoj_example: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.71.0
../bin/servoj_example: CMakeFiles/servoj_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mosab/Schreibtisch/RTDE/ur_rtde/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/servoj_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/servoj_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/servoj_example.dir/build: ../bin/servoj_example

.PHONY : CMakeFiles/servoj_example.dir/build

CMakeFiles/servoj_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/servoj_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/servoj_example.dir/clean

CMakeFiles/servoj_example.dir/depend:
	cd /home/mosab/Schreibtisch/RTDE/ur_rtde/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mosab/Schreibtisch/RTDE/ur_rtde /home/mosab/Schreibtisch/RTDE/ur_rtde /home/mosab/Schreibtisch/RTDE/ur_rtde/build /home/mosab/Schreibtisch/RTDE/ur_rtde/build /home/mosab/Schreibtisch/RTDE/ur_rtde/build/CMakeFiles/servoj_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/servoj_example.dir/depend

