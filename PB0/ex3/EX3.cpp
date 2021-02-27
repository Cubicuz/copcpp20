//
// Created by michi on 15.02.21.
//
#include "gtest/gtest.h"
#include <cstring>
#include "EX3.h"
#include <vector>
using namespace std;
void mergesort(int* arr, int len) {
    if (len > 2) {
        int mid = len/2;
        mergesort(arr, mid);
        mergesort(arr+mid, len-mid);

        // der merge part
        int* left = arr;
        int* right = arr+mid;
        int* tmp = new int[len];
        for (int i=0;i<len;i++){
            if (left < arr+mid){
                if (right < arr+len) {
                    if (*left < *right){
                        tmp[i] = *left;
                        left++;
                    } else {
                        tmp[i] = *right;
                        right++;
                    }
                } else {
                    tmp[i] = *left;
                    left++;
                }
            } else {
                tmp[i] = *right;
                right++;
            }
        }
        memcpy(arr, tmp, len*sizeof(int));
        delete tmp;

    } else if (len == 2) {
        if (arr[0] > arr[1]){
            int t = arr[0];
            arr[0] = arr[1];
            arr[1] = t;
        }
    }

}

void mergesort(vector<int> &from, vector<int> &to, int begin, int end){
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

void mergesort(vector<int> &arr, vector<int> &to) {
    vector<int> from(arr);
    mergesort(from, to, 0, from.size());
}

void isSorted(vector<int> &input, vector<int> &sorted){
    EXPECT_EQ(input.size(), sorted.size());

    for (size_t i = 0; i < input.size()-1;i++){
        EXPECT_LE(sorted[i], sorted[i+1]);
    }

    map<int, uint64_t> expectedNumbers, realNumbers;
    for (auto i : input){
        expectedNumbers[i]++;
    }
    for (auto i : input){
        realNumbers[i]++;
    }
    for (const auto& pair : expectedNumbers){
        EXPECT_EQ(pair.second, realNumbers[pair.first]);
    }
}

int* EX3::mergesort(int *a, int len) {
    int* out = new int(len);
    memcpy(out, a, len);
    return out;
}

TEST(stuff, stuff){
    map<int, int64_t> numbers;
    numbers[4]++;
    EXPECT_EQ(numbers[4], 1);
}

TEST(testMergeSort, alreadySorted) {
    int input [] = {0, 1, 2, 3};
    mergesort(input, 4);
    for (int i=0;i<4;i++){
        EXPECT_EQ(i, input[i]);
    }
}

TEST(testMergeSort, inverseSorted) {
    int input [] = {3, 2, 1, 0};
    mergesort(input, 4);
    for (int i=0;i<4;i++){
        EXPECT_EQ(i, input[i]);
    }
}

TEST(testMergeSort, rand5Sorted) {
    int input [] = {4, 3, 2, 1, 0};
    int len = 5;
    mergesort(input, len);
    for (int i=0;i<len;i++){
        EXPECT_EQ(i, input[i]);
    }
}

TEST(testMergeSort, rand7Sorted) {
    int input [] = {6, 5, 4, 3, 2, 1, 0};
    int len = 7;
    mergesort(input, len);
    for (int i=0;i<len;i++){
        EXPECT_EQ(i, input[i]);
    }
}

TEST(testVecMergeSort, alreadySorted) {
    vector<int> input = {0, 1, 2, 3};
    vector<int> out(input);
    mergesort(input, out);
    isSorted(input, out);
}

TEST(testVecMergeSort, inverseSorted) {
    vector<int> input = {3, 2, 1, 0};
    vector<int> out(input);
    mergesort(input, out);
    isSorted(input, out);
}

TEST(testVecMergeSort, rand5Sorted) {
    vector<int> input = {4, 3, 2, 1, 0};
    vector<int> out(input);
    mergesort(input, out);
    isSorted(input, out);
}

TEST(testVecMergeSort, rand7Sorted) {
    vector<int> input = {6, 5, 4, 3, 2, 1, 0};
    vector<int> out(input);
    mergesort(input, out);
    isSorted(input, out);
}
