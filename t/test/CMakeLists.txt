add_executable(cons1 cons1.cpp)

set_target_properties(cons1
    PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

add_test(NAME cons1 COMMAND cons1)

add_executable(cons2 cons2.cpp)

set_target_properties(cons2
    PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

add_test(NAME cons2 COMMAND cons2)

add_executable(access1 access1.cpp)

set_target_properties(access1
    PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

add_test(NAME access1 COMMAND access1)

add_executable(access2 access2.cpp)

set_target_properties(access2
    PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

add_test(NAME access2 COMMAND access2)

