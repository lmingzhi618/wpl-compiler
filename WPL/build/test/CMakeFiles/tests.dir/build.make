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
include test/CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/tests.dir/flags.make

test/CMakeFiles/tests.dir/lexparse/parser_tests.cpp.o: test/CMakeFiles/tests.dir/flags.make
test/CMakeFiles/tests.dir/lexparse/parser_tests.cpp.o: ../test/lexparse/parser_tests.cpp
test/CMakeFiles/tests.dir/lexparse/parser_tests.cpp.o: test/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lmz/cs544/calculator-starter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/tests.dir/lexparse/parser_tests.cpp.o"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/tests.dir/lexparse/parser_tests.cpp.o -MF CMakeFiles/tests.dir/lexparse/parser_tests.cpp.o.d -o CMakeFiles/tests.dir/lexparse/parser_tests.cpp.o -c /home/lmz/cs544/calculator-starter/test/lexparse/parser_tests.cpp

test/CMakeFiles/tests.dir/lexparse/parser_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/lexparse/parser_tests.cpp.i"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lmz/cs544/calculator-starter/test/lexparse/parser_tests.cpp > CMakeFiles/tests.dir/lexparse/parser_tests.cpp.i

test/CMakeFiles/tests.dir/lexparse/parser_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/lexparse/parser_tests.cpp.s"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lmz/cs544/calculator-starter/test/lexparse/parser_tests.cpp -o CMakeFiles/tests.dir/lexparse/parser_tests.cpp.s

test/CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.o: test/CMakeFiles/tests.dir/flags.make
test/CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.o: ../test/lexparse/scanner_tests.cpp
test/CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.o: test/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lmz/cs544/calculator-starter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.o"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.o -MF CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.o.d -o CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.o -c /home/lmz/cs544/calculator-starter/test/lexparse/scanner_tests.cpp

test/CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.i"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lmz/cs544/calculator-starter/test/lexparse/scanner_tests.cpp > CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.i

test/CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.s"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lmz/cs544/calculator-starter/test/lexparse/scanner_tests.cpp -o CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.s

test/CMakeFiles/tests.dir/symbol/symbol_tests.cpp.o: test/CMakeFiles/tests.dir/flags.make
test/CMakeFiles/tests.dir/symbol/symbol_tests.cpp.o: ../test/symbol/symbol_tests.cpp
test/CMakeFiles/tests.dir/symbol/symbol_tests.cpp.o: test/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lmz/cs544/calculator-starter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/tests.dir/symbol/symbol_tests.cpp.o"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/tests.dir/symbol/symbol_tests.cpp.o -MF CMakeFiles/tests.dir/symbol/symbol_tests.cpp.o.d -o CMakeFiles/tests.dir/symbol/symbol_tests.cpp.o -c /home/lmz/cs544/calculator-starter/test/symbol/symbol_tests.cpp

test/CMakeFiles/tests.dir/symbol/symbol_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/symbol/symbol_tests.cpp.i"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lmz/cs544/calculator-starter/test/symbol/symbol_tests.cpp > CMakeFiles/tests.dir/symbol/symbol_tests.cpp.i

test/CMakeFiles/tests.dir/symbol/symbol_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/symbol/symbol_tests.cpp.s"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lmz/cs544/calculator-starter/test/symbol/symbol_tests.cpp -o CMakeFiles/tests.dir/symbol/symbol_tests.cpp.s

test/CMakeFiles/tests.dir/semantic/semantic_tests.cpp.o: test/CMakeFiles/tests.dir/flags.make
test/CMakeFiles/tests.dir/semantic/semantic_tests.cpp.o: ../test/semantic/semantic_tests.cpp
test/CMakeFiles/tests.dir/semantic/semantic_tests.cpp.o: test/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lmz/cs544/calculator-starter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/CMakeFiles/tests.dir/semantic/semantic_tests.cpp.o"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/tests.dir/semantic/semantic_tests.cpp.o -MF CMakeFiles/tests.dir/semantic/semantic_tests.cpp.o.d -o CMakeFiles/tests.dir/semantic/semantic_tests.cpp.o -c /home/lmz/cs544/calculator-starter/test/semantic/semantic_tests.cpp

test/CMakeFiles/tests.dir/semantic/semantic_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/semantic/semantic_tests.cpp.i"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lmz/cs544/calculator-starter/test/semantic/semantic_tests.cpp > CMakeFiles/tests.dir/semantic/semantic_tests.cpp.i

test/CMakeFiles/tests.dir/semantic/semantic_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/semantic/semantic_tests.cpp.s"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lmz/cs544/calculator-starter/test/semantic/semantic_tests.cpp -o CMakeFiles/tests.dir/semantic/semantic_tests.cpp.s

test/CMakeFiles/tests.dir/codegen/codegen_tests.cpp.o: test/CMakeFiles/tests.dir/flags.make
test/CMakeFiles/tests.dir/codegen/codegen_tests.cpp.o: ../test/codegen/codegen_tests.cpp
test/CMakeFiles/tests.dir/codegen/codegen_tests.cpp.o: test/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lmz/cs544/calculator-starter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object test/CMakeFiles/tests.dir/codegen/codegen_tests.cpp.o"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/tests.dir/codegen/codegen_tests.cpp.o -MF CMakeFiles/tests.dir/codegen/codegen_tests.cpp.o.d -o CMakeFiles/tests.dir/codegen/codegen_tests.cpp.o -c /home/lmz/cs544/calculator-starter/test/codegen/codegen_tests.cpp

test/CMakeFiles/tests.dir/codegen/codegen_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/codegen/codegen_tests.cpp.i"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lmz/cs544/calculator-starter/test/codegen/codegen_tests.cpp > CMakeFiles/tests.dir/codegen/codegen_tests.cpp.i

test/CMakeFiles/tests.dir/codegen/codegen_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/codegen/codegen_tests.cpp.s"
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lmz/cs544/calculator-starter/test/codegen/codegen_tests.cpp -o CMakeFiles/tests.dir/codegen/codegen_tests.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/lexparse/parser_tests.cpp.o" \
"CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.o" \
"CMakeFiles/tests.dir/symbol/symbol_tests.cpp.o" \
"CMakeFiles/tests.dir/semantic/semantic_tests.cpp.o" \
"CMakeFiles/tests.dir/codegen/codegen_tests.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS = \
"/home/lmz/cs544/calculator-starter/build/bin/lexparse/CMakeFiles/parser_lib.dir/__/generated/CalculatorLexer.cpp.o" \
"/home/lmz/cs544/calculator-starter/build/bin/lexparse/CMakeFiles/parser_lib.dir/__/generated/CalculatorParser.cpp.o" \
"/home/lmz/cs544/calculator-starter/build/bin/symbol/CMakeFiles/sym_lib.dir/Scope.cpp.o" \
"/home/lmz/cs544/calculator-starter/build/bin/symbol/CMakeFiles/sym_lib.dir/STManager.cpp.o" \
"/home/lmz/cs544/calculator-starter/build/bin/semantic/CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.o" \
"/home/lmz/cs544/calculator-starter/build/bin/utility/CMakeFiles/utility_lib.dir/CalcErrorHandler.cpp.o" \
"/home/lmz/cs544/calculator-starter/build/bin/codegen/CMakeFiles/codegen_lib.dir/CodegenVisitor.cpp.o"

test/tests: test/CMakeFiles/tests.dir/lexparse/parser_tests.cpp.o
test/tests: test/CMakeFiles/tests.dir/lexparse/scanner_tests.cpp.o
test/tests: test/CMakeFiles/tests.dir/symbol/symbol_tests.cpp.o
test/tests: test/CMakeFiles/tests.dir/semantic/semantic_tests.cpp.o
test/tests: test/CMakeFiles/tests.dir/codegen/codegen_tests.cpp.o
test/tests: bin/lexparse/CMakeFiles/parser_lib.dir/__/generated/CalculatorLexer.cpp.o
test/tests: bin/lexparse/CMakeFiles/parser_lib.dir/__/generated/CalculatorParser.cpp.o
test/tests: bin/symbol/CMakeFiles/sym_lib.dir/Scope.cpp.o
test/tests: bin/symbol/CMakeFiles/sym_lib.dir/STManager.cpp.o
test/tests: bin/semantic/CMakeFiles/semantic_lib.dir/SemanticVisitor.cpp.o
test/tests: bin/utility/CMakeFiles/utility_lib.dir/CalcErrorHandler.cpp.o
test/tests: bin/codegen/CMakeFiles/codegen_lib.dir/CodegenVisitor.cpp.o
test/tests: test/CMakeFiles/tests.dir/build.make
test/tests: ../antlr/lib/libantlr4-runtime.a
test/tests: /usr/lib/llvm-14/lib/libLLVMCore.a
test/tests: _deps/catch2-build/src/libCatch2Maind.a
test/tests: /usr/lib/llvm-14/lib/libLLVMBinaryFormat.a
test/tests: /usr/lib/llvm-14/lib/libLLVMRemarks.a
test/tests: /usr/lib/llvm-14/lib/libLLVMBitstreamReader.a
test/tests: /usr/lib/llvm-14/lib/libLLVMSupport.a
test/tests: /usr/local/lib/libz.so
test/tests: /usr/lib/x86_64-linux-gnu/libtinfo.so
test/tests: /usr/lib/llvm-14/lib/libLLVMDemangle.a
test/tests: _deps/catch2-build/src/libCatch2d.a
test/tests: test/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lmz/cs544/calculator-starter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable tests"
	cd /home/lmz/cs544/calculator-starter/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)
	cd /home/lmz/cs544/calculator-starter/build/test && /usr/bin/cmake -D TEST_TARGET=tests -D TEST_EXECUTABLE=/home/lmz/cs544/calculator-starter/build/test/tests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/lmz/cs544/calculator-starter/build/test -D TEST_SPEC= -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_LIST=tests_TESTS -D TEST_REPORTER= -D TEST_OUTPUT_DIR= -D TEST_OUTPUT_PREFIX= -D TEST_OUTPUT_SUFFIX= -D CTEST_FILE=/home/lmz/cs544/calculator-starter/build/test/tests_tests-b12d07c.cmake -P /home/lmz/cs544/calculator-starter/build/_deps/catch2-src/extras/CatchAddTests.cmake

# Rule to build all files generated by this target.
test/CMakeFiles/tests.dir/build: test/tests
.PHONY : test/CMakeFiles/tests.dir/build

test/CMakeFiles/tests.dir/clean:
	cd /home/lmz/cs544/calculator-starter/build/test && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/tests.dir/clean

test/CMakeFiles/tests.dir/depend:
	cd /home/lmz/cs544/calculator-starter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lmz/cs544/calculator-starter /home/lmz/cs544/calculator-starter/test /home/lmz/cs544/calculator-starter/build /home/lmz/cs544/calculator-starter/build/test /home/lmz/cs544/calculator-starter/build/test/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/tests.dir/depend

