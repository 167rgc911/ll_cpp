add_executable(cons1 cons1.cpp)
add_test(NAME cons1 COMMAND cons1)

add_executable(cons2 cons2.cpp)
add_test(NAME cons2 COMMAND cons2)

add_executable(cons3 cons3.cpp)
add_test(NAME cons3 COMMAND cons3)

add_executable(access1 access1.cpp)
add_test(NAME access1 COMMAND access1)

add_executable(access2 access2.cpp)
add_test(NAME access2 COMMAND access2)

add_executable(csv csv.cpp)
target_link_libraries(csv csv_io)
add_test(NAME csv COMMAND csv)
set_property(TEST csv PROPERTY
    FAIL_REGULAR_EXPRESSION "XXX [^a-z]"
)

add_executable(csv_map csv_map.cpp)
target_link_libraries(csv_map csv_io)
add_test(NAME csv_map COMMAND csv_map)
set_property(TEST csv_map PROPERTY
    FAIL_REGULAR_EXPRESSION "XXX [^a-z]"
)

add_executable(csv_map2 csv_map2.cpp)
target_link_libraries(csv_map2 csv_io)
add_test(NAME csv_map2 COMMAND csv_map2)
set_property(TEST csv_map2 PROPERTY
    FAIL_REGULAR_EXPRESSION "XXX [^a-z]"
)

