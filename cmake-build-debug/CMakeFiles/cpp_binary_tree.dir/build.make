# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ivica/Coding/cpp-binary-tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivica/Coding/cpp-binary-tree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cpp_binary_tree.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/cpp_binary_tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpp_binary_tree.dir/flags.make

CMakeFiles/cpp_binary_tree.dir/main.cpp.o: CMakeFiles/cpp_binary_tree.dir/flags.make
CMakeFiles/cpp_binary_tree.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivica/Coding/cpp-binary-tree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpp_binary_tree.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_binary_tree.dir/main.cpp.o -c /home/ivica/Coding/cpp-binary-tree/main.cpp

CMakeFiles/cpp_binary_tree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_binary_tree.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivica/Coding/cpp-binary-tree/main.cpp > CMakeFiles/cpp_binary_tree.dir/main.cpp.i

CMakeFiles/cpp_binary_tree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_binary_tree.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivica/Coding/cpp-binary-tree/main.cpp -o CMakeFiles/cpp_binary_tree.dir/main.cpp.s

# Object files for target cpp_binary_tree
cpp_binary_tree_OBJECTS = \
"CMakeFiles/cpp_binary_tree.dir/main.cpp.o"

# External object files for target cpp_binary_tree
cpp_binary_tree_EXTERNAL_OBJECTS =

cpp_binary_tree: CMakeFiles/cpp_binary_tree.dir/main.cpp.o
cpp_binary_tree: CMakeFiles/cpp_binary_tree.dir/build.make
cpp_binary_tree: CMakeFiles/cpp_binary_tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivica/Coding/cpp-binary-tree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cpp_binary_tree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpp_binary_tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpp_binary_tree.dir/build: cpp_binary_tree
.PHONY : CMakeFiles/cpp_binary_tree.dir/build

CMakeFiles/cpp_binary_tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpp_binary_tree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpp_binary_tree.dir/clean

CMakeFiles/cpp_binary_tree.dir/depend:
	cd /home/ivica/Coding/cpp-binary-tree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivica/Coding/cpp-binary-tree /home/ivica/Coding/cpp-binary-tree /home/ivica/Coding/cpp-binary-tree/cmake-build-debug /home/ivica/Coding/cpp-binary-tree/cmake-build-debug /home/ivica/Coding/cpp-binary-tree/cmake-build-debug/CMakeFiles/cpp_binary_tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpp_binary_tree.dir/depend
