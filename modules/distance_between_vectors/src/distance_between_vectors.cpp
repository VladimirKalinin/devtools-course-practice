// Copyright 2017 Gorozhanin Mihail
#include "include/distance_between_vectors.h"
#include <vector>

float DistanceBetweenVectors::CalculateDistance(std::vector<float> vector1,
std::vector<float> vector2, Metric::TypeMetric typemetric) {
  if (vector1.size() == vector2.size()) {
    float distance;
    int size;
    std::vector<float>vect1 = vector1;
    std::vector<float>vect2 = vector2;
    size = vector1.size();
    if (typemetric == Metric::LInf) {
      float max = 0;
      for (int i = 0; i < size; i++)
        if (max < fabs(vect1[i] - vect2[i]))
          max = static_cast<float>(fabs(vect1[i] - vect2[i]));
      distance = max;
    } else {
      float Sum_Of_Components = 0;
      for (int i = 0; i < size; i++)
        Sum_Of_Components += powf(static_cast<float>
        (fabs(vect1[i] - vect2[i])),
          1.0f * static_cast<float>(typemetric));
      distance = powf(Sum_Of_Components,
      1.0f / static_cast<float>(typemetric));
    }
    return distance;
  } else {
    throw("Incorrect data");
  }
}
