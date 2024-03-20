# cmake_minimum_required(VERSION 3.28)
cmake_minimum_required(VERSION 3.16) # GH

project(aa CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# disable when using the full plethora of sanitizer options below
# set(CMAKE_CXX_CLANG_TIDY clang-tidy;-header-filter=.;-checks=-*,modernize-*)

add_compile_definitions(
    SOURCE_ROOT="${PROJECT_SOURCE_DIR}"
)

# valgrind does not work with sanitizers
# https://developers.redhat.com/blog/2021/05/05/memory-error-checking-in-c-and-c-comparing-sanitizers-and-valgrind
# gcc-7 NG
# add_compile_options(
#     "$<$<CONFIG:DEBUG>:-fsanitize=memory>"
# )
# gcc-7 NG w/ -fsanitize=address/kernel-address
# add_compile_options(
#     "$<$<CONFIG:DEBUG>:-fsanitize=thread>"
# )
add_compile_options(
    "$<$<CONFIG:DEBUG>:-fsanitize=undefined>"
)
add_compile_options(
    "$<$<CONFIG:DEBUG>:-fsanitize=address>"
)
# add_link_options(
#     "$<$<CONFIG:DEBUG>:-fsanitize=memory>"
# )
# add_link_options(
#     "$<$<CONFIG:DEBUG>:-fsanitize=thread>"
# )
add_link_options(
    "$<$<CONFIG:DEBUG>:-fsanitize=undefined>"
)
add_link_options(
    "$<$<CONFIG:DEBUG>:-fsanitize=address>"
)
# valgrind does not work with sanitizers

add_compile_options(
    "-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
    "$<$<CONFIG:DEBUG>:-fno-omit-frame-pointer;-O0;-g3;-ggdb>"
)

# use Release build!
find_program(MEMORYCHECK_COMMAND valgrind)
set(MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full")
# use Release build!

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
