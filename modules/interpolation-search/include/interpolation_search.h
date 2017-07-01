// Copyright 2017 Yashkov Vladislav + Kiparenko Ilya

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_

class InterpolationSearch {
 public:
  static int  Search(int toFind, int* sortedArray, int length);
  static bool isArrayValid(int* sortedArray, int length);
};

#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
