cmake_minimum_required(VERSION 3.8)
project(MoveBlocks)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BlockData.cpp BlockData.h GobalData.h MoveBlock.cpp MoveBlock.h MoveBlockTest.cpp MoveBlockTest.h DrawTable.h DrawTable.cpp)
add_executable(MoveBlocks ${SOURCE_FILES})