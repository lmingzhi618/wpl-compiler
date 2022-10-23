# Top-level list file for this project

cmake_minimum_required(VERSION 3.20.0)
project(WPL_COMPILER 
  LANGUAGES C CXX
  VERSION 0.1
  DESCRIPTION "Compiler to compile the WPL source to LLVM IR"
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(NoInSourceBuilds)

include(ProjectGlobals)
include(platform_settings)

set(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR})

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include(cmake/independent_settings.cmake) # Platform independent variables
include(cmake/platform_settings.cmake)     # Platform specific variables

add_subdirectory(src bin)

set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

install(
  TARGETS 
   wplc 
  DESTINATION install
)

enable_testing()
#add_subdirectory(examples)
#add_subdirectory(test)

# include(Install)
