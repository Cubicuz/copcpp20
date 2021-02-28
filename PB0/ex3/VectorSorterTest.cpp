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

TEST_P(VectorSorterTestFixture, paramtest){
    vector<int> in = GetParam();
    vector<int> out(in);
    VectorSorter::mergesort(in, out);
    isSorted(in, out);
}
vector<int> a = {2, 3, 4, 5};
vector<int> b = {4, 5, 6};
INSTANTIATE_TEST_SUITE_P(
    SortingTest,
    VectorSorterTestFixture,
    ::testing::Values(
        a, b, vector<int>({6, 5, 4})
    )
);

TEST(testVecMergeSort, alreadySorted) {
    vector<int> input = {0, 1, 2, 3};
    vector<int> out(input);
    VectorSorter::mergesort(input, out);
    VectorSorter::isSorted(input, out);
}

TEST(testVecMergeSort, inverseSorted) {
    vector<int> input = {3, 2, 1, 0};
    vector<int> out(input);
    VectorSorter::mergesort(input, out);
    VectorSorter::isSorted(input, out);
}

TEST(testVecMergeSort, rand5Sorted) {
    vector<int> input = {4, 3, 2, 1, 0};
    vector<int> out(input);
    VectorSorter::mergesort(input, out);
    VectorSorter::isSorted(input, out);
}

TEST(testVecMergeSort, rand7Sorted) {
    vector<int> input = {6, 5, 4, 3, 2, 1, 0};
    vector<int> out(input);
    VectorSorter::mergesort(input, out);
    VectorSorter::isSorted(input, out);
}
