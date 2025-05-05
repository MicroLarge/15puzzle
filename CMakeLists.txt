cmake_minimum_required(VERSION 3.10.0)
project(15_Puzzle VERSION 1.1)

include(CTest)
enable_testing()

add_executable(15_Puzzle src/main.cpp src/Board.cpp)
target_link_libraries(15_Puzzle -static -static-libgcc -static-libstdc++)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
