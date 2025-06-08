cmake_minimum_required(VERSION 3.25)
project(Task_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} functions.h struct.h main.cpp functions.cpp)
