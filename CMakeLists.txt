cmake_minimum_required(VERSION 3.13)
project(cmarktcl C)

set(CMAKE_C_STANDARD 99)

add_definitions (-DUSE_TCL_STUBS)
link_directories(/usr/local/lib/)
add_library(cmarktcl SHARED library.c library.h cmark_amalgamation.h cmark_amalgamation.c)


target_link_libraries(cmarktcl tclstub8.6)