// Copyright 2017 Kalinin Vladimir

#include "include/Sort.h"

Sort::Sort(const int array[], int length) {
    array_ = new int[length];
    length_ = length;
    for (int i = 0; i < length_; i++)
       array_[i] = array[i];
}

Sort::~Sort() {
    delete[] array_;
}

Sort& Sort::operator=(const Sort& p) {
    if (array_ == p.array_) {
        return *this;
    }
    length_ = p.length_;
    delete[]array_;
    array_ = new int[length_];
    for (int i = 0; i < length_; i++) {
        array_[i] = p.array_[i];
    }
    return *this;
}

bool Sort::operator==(const Sort & z) const {
        bool result = true;
        if (z.length_ != length_) {
           result = false;
        } else {
           for (int i = 0; i < length_; i++) {
                 if (array_[i] != z.array_[i])
                    result = false;
            }
        }
        return result;
}

void Sort::QuickSort(int left_border, int right_border) {
    int x = array_[left_border + (right_border - left_border) / 2];
    int temp;
    int i = left_border;
    int j = right_border;
    while (i <= j) {
        while (array_[i] < x) i++;
        while (array_[j] > x) j--;
        if (i <= j) {
            temp = array_[i];
            array_[i] = array_[j];
            array_[j] = temp;
            i++;
            j--;
        }
    }
    if (i < right_border)
       QuickSort(i, right_border);
    if (left_border  < j)
       QuickSort(left_border, j);
}

void Sort::PasteSort(void) {
    int counter = 0;
    for (int i = 1; i < length_; i++) {
        for (int j = i; j > 0 && array_[j - 1] > array_[j]; j--) {
            counter++;
            int tmp = array_[j - 1];
            array_[j - 1] = array_[j];
            array_[j] = tmp;
        }
    }
}

void Sort::ChoiceSort(void) {
    for (int i = 0; i < length_; i++) {
        int temp = array_[0];
        for (int j = i + 1; j < length_; j++) {
            if (array_[i] > array_[j]) {
                temp = array_[i];
                array_[i] = array_[j];
                array_[j] = temp;
            }
        }
    }
}

void Sort::merge(int first, int last) {
  int middle, start, end, j;
  int *mas = new int[100];
  middle = (first + last) / 2;
  start = first;
  end = middle + 1;
  for (j = first; j <= last; j++)
    if ((start <= middle) && ((end > last) || (array_[start] < array_[end]))) {
        mas[j] = array_[start];
        start++;
    } else {
        mas[j] = array_[end];
        end++;
    }
  for (j = first; j <= last; j++) array_[j] = mas[j];
  delete[]mas;
}

void Sort::MergeSort(int first, int last) {
     if (first < last) {
         MergeSort(first, (first + last) / 2);
         MergeSort((first + last) / 2 + 1, last);
         merge(first, last);
     }
}
