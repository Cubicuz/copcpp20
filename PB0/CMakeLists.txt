cmake_minimum_required(VERSION 3.19)
project(PB0)

add_subdirectory(googletest)
set(CMAKE_CXX_STANDARD 20)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(cpp_files
ex3/ArraySorter.cpp
ex3/EX3.cpp
ex3/VectorSorter.cpp
main.cpp
testthetests.cpp
)

set(header_files
ex3/ArraySorter.h
ex3/EX3.h
ex3/VectorSorter.h
testthetests.h
)

set(test_files
ex3/VectorSorterTest.cpp
)

add_executable(Google_Test_run ${header_files} ${cpp_files} ${test_files})
target_link_libraries(Google_Test_run gtest gtest_main)
