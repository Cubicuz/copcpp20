#include "gtest/gtest.h"
#include "VectorSorter.h"
#include <vector>
using namespace std;

class VectorSorterTestFixture :public ::testing::TestWithParam<vector<int>>{

};

void isSorted(vector<int> &in, vector<int> &out){
    EXPECT_EQ(in.size(), out.size());

    for (size_t i = 0; i < in.size()-1;i++){
        EXPECT_LE(out[i], out[i+1]);
    }

    map<int, uint64_t> expectedNumbers, realNumbers;
    for (auto i : in){
        expectedNumbers[i]++;
    }
    for (auto i : in){
        realNumbers[i]++;
    }
    for (const auto& pair : expectedNumbers){
        EXPECT_EQ(pair.second, realNumbers[pair.first]);
    }
}

TEST_P(VectorSorterTestFixture, testmergesort){
    vector<int> in = GetParam();
    vector<int> out(in);
    VectorSorter::mergesort(in, out);
    isSorted(in, out);
}

INSTANTIATE_TEST_SUITE_P(
    SortingTest,
    VectorSorterTestFixture,
    ::testing::Values(
        vector<int>({0, 1, 2, 3, 4, 5, 6}),
        vector<int>({6, 5, 4, 3, 2, 1, 0}),
        vector<int>({1}),
        vector<int>({4, 1}),
        vector<int>({4,82,36,34,4767,5,98,9,6,3,1,43,2,47,64,7,45,4,3,8,5,7,12,54,21,67,66,0})
    )
);

TEST(Sortingtest, testmergesortlongrandom){
    size_t size = 1000000;
    vector<int> in;
    in.resize(size);
    for (size_t i = 0; i<size; i++){
        in[i] = rand();
    }
    vector<int> out(in);
    VectorSorter::mergesort(in, out);
    isSorted(in, out);
}