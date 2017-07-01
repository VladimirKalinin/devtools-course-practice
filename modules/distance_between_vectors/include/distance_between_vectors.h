// Copyright 2017 Gorozhanin Mihail
#ifndef MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
#define MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_

#include <cmath>
#include <vector>
#include <iostream>

namespace Metric {
  enum TypeMetric { L1 = 1, L2, L3, L4, LInf };
}
  // Metric or the distance measure is non-negative, symmetric.
  // The Minkowski metric (L3, L4).
  // The Euclidean metric (L2).
  // Manhattan distance (L1).
  // The metric Chebyshev (LInf).


class DistanceBetweenVectors {
 public:
  static float CalculateDistance(std::vector<float> vector1,
  std::vector<float> vector2, Metric::TypeMetric typemetric);
};

#endif  // MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
