//
// Created by michi on 10.02.21.
//

#include "testthetests.h"
#include "gtest/gtest.h"
#include <chrono>

TEST(testthetest, chronoTest) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
EXPECT_LE(start, end);
}