#include "vector_it.hpp"

#include <iostream>
#include <vector>

// Implement the functions here

std::vector<int> ReadVector() {
  std::vector<int> v;
  int value;
  while (std::cin >> value) {
    v.push_back(value);
  }

  return v;
}

void PrintSum1(const std::vector<int>& v) {
  for (std::vector<int>::const_iterator it = v.begin(); it < v.end() - 1;
       it++) {
    std::cout << *it + *(it + 1) << " ";
  }
  std::cout << std::endl;
}

void PrintSum2(const std::vector<int>& v) {
  std::vector<int>::const_iterator b_it, e_it;
  b_it = v.begin();
  e_it = v.end() - 1;
  while (b_it <= e_it) {
    std::cout << *b_it + *e_it << " ";
  }
  std::cout << std::endl;
}
