// Copyright 2017 Kalinin Vladimir

#ifndef MODULES_SORT_INCLUDE_SORT_H_
#define MODULES_SORT_INCLUDE_SORT_H_

#include <stdio.h>
#include <iostream>
#include <iomanip>

class Sort {
 public:
    Sort(const int array[], int length);
    ~Sort();
    Sort(const Sort&) = delete;
    int operator[] (int i) const {return array_[i]; }
    bool operator== (const Sort& z) const;
    Sort& operator= (const Sort& p);
    void QuickSort(int left_border, int right_border);
    void PasteSort(void);
    void ChoiceSort(void);
    void MergeSort(int first, int last);
 private:
    int* array_;
    int length_;
    void merge(int first, int last);
};

#endif  // MODULES_SORT_INCLUDE_SORT_H_
