cmake_minimum_required(VERSION 3.19)
project(PB0)

add_subdirectory(googletest)
set(CMAKE_CXX_STANDARD 20)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(cpp_files
ex3/EX3.cpp
ex3/VectorSorter.cpp
main.cpp
testthetests.cpp
)

set(header_files
ex3/EX3.h
ex3/VectorSorter.h
testthetests.h
)

add_executable(Google_Test_run ${header_files} ${cpp_files})
add_executable(PB0 ${header_files} ${cpp_files})
target_link_libraries(Google_Test_run gtest gtest_main)
