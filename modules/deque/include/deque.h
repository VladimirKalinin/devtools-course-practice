// Copyright 2017 Vinogradova Ekaterina

#ifndef MODULES_DEQUE_INCLUDE_DEQUE_H_
#define MODULES_DEQUE_INCLUDE_DEQUE_H_

#include <iostream>

const int kDefMemSize = 25;

typedef double    Elem;
typedef Elem*    PointElem;

class Deque {
 public:
    explicit Deque(int size = kDefMemSize);
    ~Deque();
    void InsFront(Elem element);
    void InsBack(Elem element);
    Elem GetFront();
    Elem GetBack();
    bool IsEmpty(void) const;
    bool IsFull(void) const;
 protected:
    PointElem memory_;
    int front_;
    int back_;
    int mem_size_;
    int data_count_;

    int GetNextFrontIndex(int index);
    int GetNextBackIndex(int index);
};

#endif  // MODULES_DEQUE_INCLUDE_DEQUE_H_
