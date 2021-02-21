#include <iostream>
#include <chrono>
#include "gtest/gtest.h"

int main(int argc,char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

TEST(blublub, chronoTest) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    EXPECT_LE(start, end);
}