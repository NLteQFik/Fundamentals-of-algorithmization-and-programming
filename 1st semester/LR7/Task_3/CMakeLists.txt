cmake_minimum_required(VERSION 3.25)
project(Task_3)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")

add_executable(${PROJECT_NAME} Header.h main.cpp Addition.cpp IntegerInput.cpp Reconvert.cpp SignCheck.cpp SignInput.cpp StartAndEnd.cpp StrConvert.cpp StringInput.cpp Subtraction.cpp)