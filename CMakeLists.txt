cmake_minimum_required(VERSION 3.16)
project(splittest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(main stats.cpp ab_test.cpp main.cpp)

add_subdirectory(lib/googletest/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(test stats.cpp stats_test.cpp)
target_link_libraries(test gtest gtest_main)