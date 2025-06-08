cmake_minimum_required(VERSION 3.25)
project(LR1)

find_package (GTest REQUIRED)

add_executable(LR1 Task_3.cpp)
target_link_libraries(LR1 ${GTEST_LIBRARIES})

enable_testing()
add_test(add LR1)