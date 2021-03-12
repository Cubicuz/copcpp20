#ifndef PB0_ex3_MyList_H
#define PB0_ex3_MyList_H

#include <iterator>
#include <list>

template<typename T>
class MyList {
public:
    void append(T t) = 0;
    void insert(int idx, T t) = 0;
    T get(int idx);
    bool contains(T o);
    int indexOf(T o);
    void clear();
    int size();
    T remove(int idx);
    MyList<T> subList(int from, int to);
    std::bidirectional_iterator begin;
    class Iterator
    {
        // do this: https://vector-of-bool.github.io/2020/06/13/cpp20-iter-facade.html
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;  // or also value_type*
        using reference         = T&;  // or also value_type&

        reference operator*() const;
        pointer operator->();

        // prefix
        Iterator operator++();
        // postfix
        Iterator operator++(int);
        // prefix
        Iterator operator--();
        // postfix
        Iterator operator--(int);

        bool operator== (const Iterator& a, const Iterator& b);
        bool operator!= (const Iterator& a, const Iterator& b);
    };    
};

#endif //PB0_ex3_MyList_H