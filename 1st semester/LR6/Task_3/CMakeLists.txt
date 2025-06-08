cmake_minimum_required(VERSION 3.25)
project(Task_3)

find_package (GTest REQUIRED)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")

add_executable(${PROJECT_NAME} Header.h main.cpp ArraySolve.cpp ArrayStringOutput.cpp BufferInput.cpp Fill.cpp NumberOfDigits.cpp Solve.cpp StartAndEnd.cpp StringArrayInput.cpp StringOutput.cpp SymbolInput.cpp SymbolOutput.cpp)

target_link_libraries(Task_3 ${GTEST_LIBRARIES})

enable_testing()
add_test(add Task_3)