#ifndef PB0_ex3_VectorSorter_H
#define PB0_ex3_VectorSorter_H

#include <vector>

class VectorSorter
{
public:
    static void mergesort(std::vector<int> &in, std::vector<int> &out);
    static void isSorted(std::vector<int> &in, std::vector<int> &out);
private:
    static void mergesort(std::vector<int> &from, std::vector<int> &to, int begin, int end);
};

#endif //PB0_ex3_VectorSorter_H
