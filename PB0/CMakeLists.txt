cmake_minimum_required(VERSION 3.19)
project(PB0)

add_subdirectory(googletest)
set(CMAKE_CXX_STANDARD 20)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(cpp_files
        testthetests.h
        testthetests.cpp
        main.cpp
        EX3.cpp
        EX3.h)

add_executable(Google_Test_run ${cpp_files})
add_executable(PB0 ${cpp_files})
target_link_libraries(Google_Test_run gtest gtest_main)
