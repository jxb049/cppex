# - Main CMake script for pp6calculator
# Comments in CMake begin with a '#' just like shell and python scripts
#
# - Require latest generation of CMake
cmake_minimum_required(VERSION 2.6.4 FATAL_ERROR)

# - Declare the project
project(cppex)

# - Use standard flag set when using the GNU compiler
if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "-std=c++98 -pedantic-errors -Wall -Werror -Wfatal-errors -Wwrite-strings -Woverloaded-virtual -fno-nonansi-builtins -fno-gnu-keywords -fstrict-aliasing")
endif()

# - Tell compiler where to find headers
include_directories(PP6Lib Week1 Week2 Week3 FileReader)

# - Add the PP6Lib library
add_subdirectory(PP6Lib)
add_subdirectory(Week1)
add_subdirectory(Week2)
add_subdirectory(Week3)
add_subdirectory(FileReader)

# - Add the pp6calculator program
add_executable(ex2 ex2.cpp)

# - Link ex2 to the pp6lib library
target_link_libraries(ex2 pp6lib Week1 Week2 Week3 FileReader)

# - Install pp6calculator to the bin subdirectory of CMAKE_INSTALL_PREFIX
install(TARGETS ex2 DESTINATION bin)

# - Package pp6calculator sources and executable
include(CPack)
