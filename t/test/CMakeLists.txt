add_executable(cons cons.cpp)

set_target_properties(cons
    PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

add_test(NAME cons COMMAND cons)

