# Top-level list file for this project

cmake_minimum_required(VERSION 3.20.0)
project(WPL_COMPILER 
  LANGUAGES C CXX
  VERSION 0.1
  DESCRIPTION "Compiler to compile the WPL source to LLVM IR"
)


find_package(LLVM REQUIRED CONFIG)
list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})

include(ChooseMSVCCRT)
include(AddLLVM)
include(HandleLLVMOptions)
include_directories("${LLVM_BINARY_DIR}/include" "${LLVM_INCLUDE_DIR}")
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
link_directories("${LLVM_LIBRARY_DIR}")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")


set(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR})


include(NoInSourceBuilds)
include(ProjectGlobals)
include(platform_settings)
include(independent_settings) # Platform independent variables

add_subdirectory(src bin)

set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

install(
  TARGETS 
   wplc 
  DESTINATION install
)

enable_testing()
#add_subdirectory(examples)
#add_subdirectory(test)

# include(Install)
