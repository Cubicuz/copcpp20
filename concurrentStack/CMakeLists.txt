cmake_minimum_required(VERSION 3.0.0)
project(concurrentStack VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

add_executable(concurrentStack main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(Catch2 REQUIRED)

add_executable(tests test/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2)

target_compile_options(tests PRIVATE "-DCATCH_CONFIG_ENABLE_BENCHMARKING")

include(CTest)
include(Catch)
catch_discover_tests(tests)
