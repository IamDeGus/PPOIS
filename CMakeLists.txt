cmake_minimum_required(VERSION 4.1)
project(CookingProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Опция для coverage (как у вас было)
option(CODE_COVERAGE "Enable coverage reporting" ON)

# if(CODE_COVERAGE)
#     message(STATUS "Building with code coverage enabled")
#     # Флаги для gcc/g++
#     add_compile_options(--coverage)
#     add_link_options(--coverage)
# endif()

add_subdirectory(src)
add_subdirectory(tests)

