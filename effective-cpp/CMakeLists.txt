cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-g -O0 -stdlib=libc++")

project(Effective-CPP LANGUAGES CXX)

find_package(benchmark REQUIRED)

file(GLOB SRC_FILES *.cpp)

add_executable(ch1-bm ch1-accustoming-your-self-to-cpp.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(ch1-bm benchmark::benchmark)
