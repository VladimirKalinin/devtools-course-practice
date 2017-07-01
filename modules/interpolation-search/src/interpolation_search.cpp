// Copyright 2017 Yashkov Vladislav + Kiparenko Ilya

#include "include/interpolation_search.h"

bool InterpolationSearch::isArrayValid(int* sortedArray, int length) {
  if (sortedArray == nullptr) {
    throw "Array is null";
  } else {
    if (length < 1) {
      throw "length is null or negative";
    } else {
      for (int i = 1; i < length; i++)
        if (sortedArray[i] < sortedArray[i - 1])
          return false;
      return true;
    }
  }
  return false;
}

int InterpolationSearch::Search(int toFind, int* sortedArray, int length) {
  // Returns the index of an element with a value of toFind or -1,
  // if there is no such element
  int low = 0;
  int high = length - 1;
  while (sortedArray[low] < toFind && sortedArray[high] > toFind) {
    int mid = low + ((toFind - sortedArray[low]) *
      (high - low)) / (sortedArray[high] - sortedArray[low]);
    if (sortedArray[mid] < toFind)
      low = mid + 1;
    else if (sortedArray[mid] > toFind)
      high = mid - 1;
    else
      return mid;
  }
  if (sortedArray[low] == toFind) {
    return low;
  } else {
    if (sortedArray[high] == toFind)
      return high;
    else
      return -1;  // Not found
  }
  return -1;
}
