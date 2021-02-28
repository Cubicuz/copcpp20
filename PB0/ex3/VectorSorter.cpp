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

bool VectorSorter::isSorted(vector<int> &in, vector<int> &out){
    if (in.size() != out.size()){
        return false;
    }
    for (size_t i = 0; i < in.size()-1;i++){
        if (out[i+1] > out [i]){
            return false;
        }
    }

    map<int, uint64_t> expectedNumbers, realNumbers;
    for (auto i : in){
        expectedNumbers[i]++;
    }
    for (auto i : in){
        realNumbers[i]++;
    }
    for (const auto& pair : expectedNumbers){
        if (pair.second != realNumbers[pair.first]){
            return false;
        }
    }
    return true;
}
