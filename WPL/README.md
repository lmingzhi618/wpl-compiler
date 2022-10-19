# Calculator -- reference compiler application

The details for this project are in the course notebooks. However, much of the information is also provided here.

## Setup

1. You have already unzipped the archive and are looking at this file. We will call this directory `PROJECT_ROOT`.

2. Copy or move the `antlr/antlr4-cpp-runtime.zip` archive to a separate directory. You could unzip it in place, but that introduces more complexity than you want. The directory where you unzipped it we will call `ANTLR_ROOT`.

3. In a terminal, go to the `ANTLR_ROOT` the following commands in order (this will take a few minutes).
  - `cmake -S . -B build`
  - `cmake --build build`

4. Go to the `build` directory and run the command `ctest`. This will run the tests and you should get no errors.

5. Go to the `ANTLR_ROOT/dist` directory. There will be one or more libraries there. Depending upon your platform, these might have different names. You want to take the one that is a static library and move it to the `PROJECT_ROOT/antlr/lib`. If the name of the library is not `libantlr4-runtime.a`, then modify the `PROJECT_ROOT/src/cmake/antlr.cmake` by changing the library name. NOTE: There is a `libantlr4-runtime.a` in the directory. You should overwrite this or remove it.

6. If you do not have the ability to run a `bash` script then you need to modify the `PROJECT_ROOT/src/lexparse/generate.sh` script. See instructions below. If you can run `bash` scripts you can skip this step.

7. Now go to the `PROJECT_ROOT` directory. and executed the following commands in order:
  - `cmake -S . -B build`
  - `cmake --build build` 
  - `cmake -- install build`
  - `install/calculator`

You should see output of: `<EOF> <EOF>`. If you do, congratulations, you're all set. If there are errors you need to do some debugging. Ask for help from the staff or on the Slack #toolchain channel.

---

## If you have to modify the `PROJECT_ROOT/src/lexparse/generate.sh` script

This script looks like this in the initial project:

```
#! /usr/bin/env bash

if [ ! -f ../generated/$1Parser.cpp ] || [ "$1.g4" -nt "../generated/$1Parser.cpp" ]; 
then 
  echo ">>> Generating <<<"
  pwd
  java -jar ../../antlr/antlr4.jar -Dlanguage=Cpp -visitor -listener -o ../generated $1.g4 
  touch parser_sources.h
fi
```

You should create an equivalent script for your platform, but name it something different; something like `generate.win`. **Do not change the original script**. Here is what the script does:

1. Check to see if there is a `CalculatorParser.cpp` file in the `generated` directory. 

2. If there is no `CalculatorParser.cpp`, or if the `Calculator.g4` has a new timestamp than the `CalculatorParser.gpp` file, then it runs ANTLR to create the scanner, parser, parse tree visitor, and parser tree listener in the `generated` directory.

3. When done, create or update the timestamp on `parser_sources.h`, which is a dummy file in the `lexparse` folder.

If you do not want to do all of this, you can just make the script run ANTLR without any checks. This will add just a short amout of time to your builds because it will build the scanner and parser every time you do a build.

If you have changed the script, you will also need to change the `lexparse/CMakeLists.txt` file to modify the custom command:

```
add_custom_command(
  OUTPUT(
    ${CMAKE_CURRENT_SOURCE_DIR}/parser_sources.h
  )
  BYPRODUCTS ${ANTLR_SOURCES}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMAND /bin/sh  generate.sh Calculator       # Change this if you have a different script
)
```

---

## References and readings

\[1] *ANTLR Parsing and C++*, Matt Scarpino, Code Project, 2021. https://www.codeproject.com/Articles/5308882/ANTLR-Parsing-and-Cplusplus-Part-1-Introduction, .

[1]: https://www.codeproject.com/Articles/5308882/ANTLR-Parsing-and-Cplusplus-Part-1-Introduction (*ANTLR Parsing and C++*, Matt Scarpino, Code Project, 2021.)
