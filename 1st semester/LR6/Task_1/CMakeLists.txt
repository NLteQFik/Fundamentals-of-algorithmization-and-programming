cmake_minimum_required(VERSION 3.25)
project(Task_1)

find_package (GTest REQUIRED)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")

add_executable(${PROJECT_NAME} Header.h main.cpp FindShortAndType.cpp Min.cpp ZeroesAndOnesCheck.cpp ZeroesAndOnesInput.cpp StartAndEnd.cpp)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})

enable_testing()
add_test(add Task_1)