cmake_minimum_required(VERSION 3.25)
project(Task_2)

find_package (GTest REQUIRED)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")

add_executable(${PROJECT_NAME} Header.h main.cpp BufferInpur.cpp IntegerInput.cpp Solve.cpp StartAndEnd.cpp StringInput.cpp StringOutput.cpp SymbolInput.cpp SymbolOutput.cpp)

target_link_libraries(Task_2 ${GTEST_LIBRARIES})

enable_testing()
add_test(add Task_2)