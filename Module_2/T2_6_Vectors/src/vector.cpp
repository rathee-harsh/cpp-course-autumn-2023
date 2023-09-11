#include "vector.hpp"

#include <vector>

int GetMin(std::vector<int> v) {
  int smallest = 1000;
  for (unsigned int i = 0; i < v.size(); i++) {
    if (v[i] < smallest) {
      smallest = v[i];
    }
  }
  return smallest;
}

int GetMax(std::vector<int> v) {
  int largest = -1000;
  for (unsigned int i = 0; i < v.size(); i++) {
    if (v[i] > largest) {
      largest = v[i];
    }
  }
  return largest;
}

double GetAvg(std::vector<int> v) {
  if (v.size() == 0) {
    return 0;
  }
  int sum = 0;
  for (unsigned int i = 0; i < v.size(); i++) {
    sum += v[i];
  }
  return 1.0 * sum / v.size();
}
