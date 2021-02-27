#include "ArraySorter.h"
#include "gtest/gtest.h"
#include <cstring>

void ArraySorter::mergesort(int* arr, int len)
{
    if (len > 2) {
        int mid = len/2;
        mergesort(arr, mid);
        mergesort(arr+mid, len-mid);

        // der merge part
        int *left = arr;
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

TEST(testArrayMergeSort, alreadySorted) {
    int input [] = {0, 1, 2, 3};
    ArraySorter::mergesort(input, 4);
    for (int i=0;i<4;i++){
        EXPECT_EQ(i, input[i]);
    }
}

TEST(testArrayMergeSort, inverseSorted) {
    int input [] = {3, 2, 1, 0};
    ArraySorter::mergesort(input, 4);
    for (int i=0;i<4;i++){
        EXPECT_EQ(i, input[i]);
    }
}

TEST(testArrayMergeSort, rand5Sorted) {
    int input [] = {4, 3, 2, 1, 0};
    int len = 5;
    ArraySorter::mergesort(input, len);
    for (int i=0;i<len;i++){
        EXPECT_EQ(i, input[i]);
    }
}

TEST(testArrayMergeSort, rand7Sorted) {
    int input [] = {6, 5, 4, 3, 2, 1, 0};
    int len = 7;
    ArraySorter::mergesort(input, len);
    for (int i=0;i<len;i++){
        EXPECT_EQ(i, input[i]);
    }
}