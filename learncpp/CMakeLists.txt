cmake_minimum_required(VERSION 3.28)
project(learncpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SRC_FILES src/*.cpp)

include_directories(/opt/homebrew/opt/gcc/include/c++/14/)

foreach (SRC_FILE ${SRC_FILES})
    get_filename_component(EXEC_NAME ${SRC_FILE} NAME_WE)
    add_executable(${EXEC_NAME} ${SRC_FILE})
endforeach ()