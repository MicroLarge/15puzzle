cmake_minimum_required(VERSION 3.5.0)
project(15_Puzzle VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(15_Puzzle src/main.cpp src/Board.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
