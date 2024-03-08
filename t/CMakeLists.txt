cmake_minimum_required(VERSION 3.28)

project(aa CXX)

find_program( MEMORYCHECK_COMMAND valgrind )
set( MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full" )

find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (CMAKE_CXX_CPPCHECK)
    list(
        APPEND CMAKE_CXX_CPPCHECK 
            "--enable=warning"
            "--inconclusive"
            "--force" 
            "--inline-suppr"
            "--suppressions-list=${CMAKE_SOURCE_DIR}/CppCheckSuppressions.txt"
    )
endif()

add_compile_options(
    "-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
    "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)

add_subdirectory(src)

include(CTest)
add_subdirectory(test)
