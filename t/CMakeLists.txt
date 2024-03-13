# cmake_minimum_required(VERSION 3.28)
cmake_minimum_required(VERSION 3.16) # GH

project(aa CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# set(CMAKE_CXX_CLANG_TIDY clang-tidy; -header-filter=.; -checks=-*,modernize-*)

add_compile_options($<$<CONFIG:DEBUG>:-fsanitize=address>)
add_link_options($<$<CONFIG:DEBUG>:-fsanitize=address>)

add_compile_options(
    "-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
    "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)

find_program(MEMORYCHECK_COMMAND valgrind)
set(MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full")

# find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
# if (CMAKE_CXX_CPPCHECK)
#     list(
#         APPEND CMAKE_CXX_CPPCHECK
#             "--enable=warning"
#             "--inconclusive"
#             "--force"
#             "--inline-suppr"
#             "--suppressions-list=${CMAKE_SOURCE_DIR}/CppCheckSuppressions.txt"
#     )
# endif()

include_directories(include)

add_subdirectory(src)

include(CTest)
add_subdirectory(test)
