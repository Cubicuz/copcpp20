#include "VectorSorter.h"
#include "gtest/gtest.h"

using namespace std;

void VectorSorter::mergesort(vector<int> &from, vector<int> &to, int begin, int end)
{
    if (end-begin == 1){
        to[begin] = from[begin];
        return;
    }
    int mid = (end - begin) / 2 + begin;
    mergesort(to, from, begin, mid);
    mergesort(to, from, mid, end);
    int left = begin;
    int right = mid;
    //merge
    for (int i=begin; i<end;i++){
        if (left < mid){
            if (right < end){
                if (from[left] < from[right]){
                    to[i] = from[left];
                    left++;
                } else {
                    to[i] = from[right];
                    right++;
                }
            } else {
                to[i] = from[left];
                left++;
            }
        } else {
            to[i] = from[right];
            right++;
        }
    }
}

void VectorSorter::mergesort(vector<int> &in, vector<int> &to) {
    vector<int> from(in);
    mergesort(from, to, 0, from.size());
}

void VectorSorter::isSorted(vector<int> &in, vector<int> &out){
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
