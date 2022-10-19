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
include bin/CMakeFiles/calculator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include bin/CMakeFiles/calculator.dir/compiler_depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/calculator.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/calculator.dir/flags.make

bin/CMakeFiles/calculator.dir/calculator.cpp.o: bin/CMakeFiles/calculator.dir/flags.make
bin/CMakeFiles/calculator.dir/calculator.cpp.o: ../src/calculator.cpp
bin/CMakeFiles/calculator.dir/calculator.cpp.o: bin/CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lmz/cs544/calculator-starter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/calculator.dir/calculator.cpp.o"
	cd /home/lmz/cs544/calculator-starter/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT bin/CMakeFiles/calculator.dir/calculator.cpp.o -MF CMakeFiles/calculator.dir/calculator.cpp.o.d -o CMakeFiles/calculator.dir/calculator.cpp.o -c /home/lmz/cs544/calculator-starter/src/calculator.cpp

bin/CMakeFiles/calculator.dir/calculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calculator.dir/calculator.cpp.i"
	cd /home/lmz/cs544/calculator-starter/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lmz/cs544/calculator-starter/src/calculator.cpp > CMakeFiles/calculator.dir/calculator.cpp.i

bin/CMakeFiles/calculator.dir/calculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/calculator.cpp.s"
	cd /home/lmz/cs544/calculator-starter/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lmz/cs544/calculator-starter/src/calculator.cpp -o CMakeFiles/calculator.dir/calculator.cpp.s

# Object files for target calculator
calculator_OBJECTS = \
"CMakeFiles/calculator.dir/calculator.cpp.o"

# External object files for target calculator
calculator_EXTERNAL_OBJECTS = \
"/home/lmz/cs544/calculator-starter/build/bin/lexparse/CMakeFiles/parser_lib.dir/__/generated/CalculatorLexer.cpp.o" \
"/home/lmz/cs544/calculator-starter/build/bin/lexparse/CMakeFiles/parser_lib.dir/__/generated/CalculatorParser.cpp.o" \
"/home/lmz/cs544/calculator-starter/build/bin/symbol/CMakeFiles/sym_lib.dir/Scope.cpp.o" \
"/home/lmz/cs544/calculator-starter/build/bin/symbol/CMakeFiles/sym_lib.dir/STManager.cpp.o" \
"/home/lmz/cs544/calculator-starter/build/bin/semantic/CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.o" \
"/home/lmz/cs544/calculator-starter/build/bin/utility/CMakeFiles/utility_lib.dir/CalcErrorHandler.cpp.o" \
"/home/lmz/cs544/calculator-starter/build/bin/codegen/CMakeFiles/codegen_lib.dir/CodegenVisitor.cpp.o"

bin/calculator: bin/CMakeFiles/calculator.dir/calculator.cpp.o
bin/calculator: bin/lexparse/CMakeFiles/parser_lib.dir/__/generated/CalculatorLexer.cpp.o
bin/calculator: bin/lexparse/CMakeFiles/parser_lib.dir/__/generated/CalculatorParser.cpp.o
bin/calculator: bin/symbol/CMakeFiles/sym_lib.dir/Scope.cpp.o
bin/calculator: bin/symbol/CMakeFiles/sym_lib.dir/STManager.cpp.o
bin/calculator: bin/semantic/CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.o
bin/calculator: bin/utility/CMakeFiles/utility_lib.dir/CalcErrorHandler.cpp.o
bin/calculator: bin/codegen/CMakeFiles/codegen_lib.dir/CodegenVisitor.cpp.o
bin/calculator: bin/CMakeFiles/calculator.dir/build.make
bin/calculator: ../antlr/lib/libantlr4-runtime.a
bin/calculator: /usr/lib/llvm-14/lib/libLLVMCore.a
bin/calculator: /usr/lib/llvm-14/lib/libLLVMBinaryFormat.a
bin/calculator: /usr/lib/llvm-14/lib/libLLVMRemarks.a
bin/calculator: /usr/lib/llvm-14/lib/libLLVMBitstreamReader.a
bin/calculator: /usr/lib/llvm-14/lib/libLLVMSupport.a
bin/calculator: /usr/local/lib/libz.so
bin/calculator: /usr/lib/x86_64-linux-gnu/libtinfo.so
bin/calculator: /usr/lib/llvm-14/lib/libLLVMDemangle.a
bin/calculator: bin/CMakeFiles/calculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lmz/cs544/calculator-starter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable calculator"
	cd /home/lmz/cs544/calculator-starter/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calculator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/calculator.dir/build: bin/calculator
.PHONY : bin/CMakeFiles/calculator.dir/build

bin/CMakeFiles/calculator.dir/clean:
	cd /home/lmz/cs544/calculator-starter/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/calculator.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/calculator.dir/clean

bin/CMakeFiles/calculator.dir/depend:
	cd /home/lmz/cs544/calculator-starter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lmz/cs544/calculator-starter /home/lmz/cs544/calculator-starter/src /home/lmz/cs544/calculator-starter/build /home/lmz/cs544/calculator-starter/build/bin /home/lmz/cs544/calculator-starter/build/bin/CMakeFiles/calculator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/calculator.dir/depend

