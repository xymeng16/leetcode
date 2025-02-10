cmake_minimum_required(VERSION 3.28)

project(learncpp)

set(CMAKE_CXX_STANDARD 23)

# for each source file in src/, create an executable with the same name
file(GLOB SRC_FILES src/*.cpp)
foreach (SRC_FILE ${SRC_FILES})
    get_filename_component(EXEC_NAME ${SRC_FILE} NAME_WE)
    add_executable(${EXEC_NAME} ${SRC_FILE})
endforeach ()