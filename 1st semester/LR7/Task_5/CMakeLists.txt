cmake_minimum_required(VERSION 3.25)
project(Task_5)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")

add_executable(${PROJECT_NAME} Header.h main.cpp Bochkas.cpp Convert.cpp IntegerInput.cpp Reconvert.cpp StartAndEnd.cpp)