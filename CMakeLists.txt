cmake_minimum_required(VERSION 4.1)
project(GameTicTacToe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


add_subdirectory(GameLogic)
add_subdirectory(TUI)
add_subdirectory(Tests)


add_executable(GameTicTacToe main.cpp)


target_link_libraries(GameTicTacToe PRIVATE GameLogic TUI ncurses)
