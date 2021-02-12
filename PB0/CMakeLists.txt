cmake_minimum_required(VERSION 3.19)
project(PB0)

add_subdirectory(googletest)
set(CMAKE_CXX_STANDARD 20)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(Google_Test_run main.cpp testthetests.cpp testthetests.h)
add_executable(PB0 main.cpp testthetests.cpp testthetests.h)
target_link_libraries(Google_Test_run gtest gtest_main)
