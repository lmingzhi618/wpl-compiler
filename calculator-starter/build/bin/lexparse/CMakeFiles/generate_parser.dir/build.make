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
CMAKE_SOURCE_DIR = /home/lmz/calculator-starter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lmz/calculator-starter/build

# Utility rule file for generate_parser.

# Include any custom commands dependencies for this target.
include bin/lexparse/CMakeFiles/generate_parser.dir/compiler_depend.make

# Include the progress variables for this target.
include bin/lexparse/CMakeFiles/generate_parser.dir/progress.make

bin/lexparse/CMakeFiles/generate_parser: ../src/lexparse/parser_sources.h

bin/lexparse/(:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lmz/calculator-starter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating (, ../../../src/lexparse/parser_sources.h, )"
	cd /home/lmz/calculator-starter/src/lexparse && /bin/sh generate.sh Calculator

../src/lexparse/parser_sources.h: bin/lexparse/(
	@$(CMAKE_COMMAND) -E touch_nocreate ../src/lexparse/parser_sources.h

bin/lexparse/): bin/lexparse/(
	@$(CMAKE_COMMAND) -E touch_nocreate "bin/lexparse/)"

generate_parser: bin/lexparse/(
generate_parser: bin/lexparse/)
generate_parser: bin/lexparse/CMakeFiles/generate_parser
generate_parser: ../src/lexparse/parser_sources.h
generate_parser: bin/lexparse/CMakeFiles/generate_parser.dir/build.make
.PHONY : generate_parser

# Rule to build all files generated by this target.
bin/lexparse/CMakeFiles/generate_parser.dir/build: generate_parser
.PHONY : bin/lexparse/CMakeFiles/generate_parser.dir/build

bin/lexparse/CMakeFiles/generate_parser.dir/clean:
	cd /home/lmz/calculator-starter/build/bin/lexparse && $(CMAKE_COMMAND) -P CMakeFiles/generate_parser.dir/cmake_clean.cmake
.PHONY : bin/lexparse/CMakeFiles/generate_parser.dir/clean

bin/lexparse/CMakeFiles/generate_parser.dir/depend:
	cd /home/lmz/calculator-starter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lmz/calculator-starter /home/lmz/calculator-starter/src/lexparse /home/lmz/calculator-starter/build /home/lmz/calculator-starter/build/bin/lexparse /home/lmz/calculator-starter/build/bin/lexparse/CMakeFiles/generate_parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/lexparse/CMakeFiles/generate_parser.dir/depend

