add_executable(aa aa.cpp)

add_library(csv_io STATIC csv.cpp)

add_custom_target(timer_h2
  COMMAND cppfront-0.7.0 -verbose -emit-cppfront-info -import-std -pure-cpp2 timer.h2
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/cpp2
)

add_library(timer STATIC timer.cpp)
add_dependencies(timer timer_h2)
target_include_directories(timer PUBLIC ${PROJECT_SOURCE_DIR}/cpp2)
target_include_directories(timer PUBLIC $ENV{HOME}/u/include)
