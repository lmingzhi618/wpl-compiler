# Top-level list file for this project

cmake_minimum_required(VERSION 3.20.0)
project(expressions 
  LANGUAGES CXX
  VERSION 0.1
  DESCRIPTION "Reference compiler to compile a simple expression language to LLVM IR"
)
set(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR})

include(cmake/independent_settings.cmake) # Platform independent variables
include(cmake/platform_settings.cmake)     # Platform specific variables

add_subdirectory(src bin)

set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
install(
  TARGETS 
    calculator
  DESTINATION install
)

enable_testing()
add_subdirectory(test)

# include(Install)
