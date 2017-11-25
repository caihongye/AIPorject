cmake_minimum_required(VERSION 3.8)
project(MoveBlock)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BlockData.cpp BlockData.h GobalData.h MoveBlock.cpp MoveBlock.h)
add_executable(MoveBlock ${SOURCE_FILES})