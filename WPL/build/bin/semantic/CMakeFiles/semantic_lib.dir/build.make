# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/lmz/cs544/calculator-starter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lmz/cs544/calculator-starter/build

# Include any dependencies generated for this target.
include bin/semantic/CMakeFiles/semantic_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include bin/semantic/CMakeFiles/semantic_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include bin/semantic/CMakeFiles/semantic_lib.dir/progress.make

# Include the compile flags for this target's objects.
include bin/semantic/CMakeFiles/semantic_lib.dir/flags.make

bin/semantic/CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.o: bin/semantic/CMakeFiles/semantic_lib.dir/flags.make
bin/semantic/CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.o: ../src/semantic/SemanticVisitor.cpp
bin/semantic/CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.o: bin/semantic/CMakeFiles/semantic_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lmz/cs544/calculator-starter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/semantic/CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.o"
	cd /home/lmz/cs544/calculator-starter/build/bin/semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT bin/semantic/CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.o -MF CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.o.d -o CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.o -c /home/lmz/cs544/calculator-starter/src/semantic/SemanticVisitor.cpp

bin/semantic/CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.i"
	cd /home/lmz/cs544/calculator-starter/build/bin/semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lmz/cs544/calculator-starter/src/semantic/SemanticVisitor.cpp > CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.i

bin/semantic/CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.s"
	cd /home/lmz/cs544/calculator-starter/build/bin/semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lmz/cs544/calculator-starter/src/semantic/SemanticVisitor.cpp -o CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.s

semantic_lib: bin/semantic/CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.o
semantic_lib: bin/semantic/CMakeFiles/semantic_lib.dir/build.make
.PHONY : semantic_lib

# Rule to build all files generated by this target.
bin/semantic/CMakeFiles/semantic_lib.dir/build: semantic_lib
.PHONY : bin/semantic/CMakeFiles/semantic_lib.dir/build

bin/semantic/CMakeFiles/semantic_lib.dir/clean:
	cd /home/lmz/cs544/calculator-starter/build/bin/semantic && $(CMAKE_COMMAND) -P CMakeFiles/semantic_lib.dir/cmake_clean.cmake
.PHONY : bin/semantic/CMakeFiles/semantic_lib.dir/clean

bin/semantic/CMakeFiles/semantic_lib.dir/depend:
	cd /home/lmz/cs544/calculator-starter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lmz/cs544/calculator-starter /home/lmz/cs544/calculator-starter/src/semantic /home/lmz/cs544/calculator-starter/build /home/lmz/cs544/calculator-starter/build/bin/semantic /home/lmz/cs544/calculator-starter/build/bin/semantic/CMakeFiles/semantic_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/semantic/CMakeFiles/semantic_lib.dir/depend
