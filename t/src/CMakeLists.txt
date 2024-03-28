add_executable(aa aa.cpp)

add_library(csv_io STATIC csv.cpp)

add_library(timer STATIC timer.cpp)
target_include_directories(timer PUBLIC ${PROJECT_SOURCE_DIR}/cpp2)
target_include_directories(timer PUBLIC $ENV{HOME}/u/include)
