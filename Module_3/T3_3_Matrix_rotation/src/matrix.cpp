#include "matrix.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

// Implement the functions here
// Remember to use auto and ranged for-loops when they can be used!

// Assumes 'm' is a square matrix
Matrix ReadMatrix(int n) {
  Matrix matrix;
  for (int i = 0; i < n; i++) {
    std::vector<int> new_row;
    for (int j = 0; j < n; j++) {
      int e;
      std::cin >> e;
      new_row.push_back(e);
    }
    matrix.push_back(new_row);
  }
  return matrix;
}

Matrix Rotate90Deg(const Matrix &m) {
  Matrix r;
  for (std::vector<std::vector<int>>::size_type i = 0; i < m.size(); i++) {
    std::vector<int> row(m.size());
    r.push_back(row);
  }
  for (std::vector<std::vector<int>>::size_type i = 0; i < m.size(); i++) {
    for (std::vector<std::vector<int>>::size_type j = 0; j <= i; j++) {
      r[j][i] = m[i][j];
      r[i][j] = m[j][i];
    }
  }
  for (std::vector<std::vector<int>>::size_type i = 0; i < m.size(); i++) {
    std::reverse(r[i].begin(), r[i].end());
  }
  return r;
}

void Print(const Matrix &m) {
  std::cout << "Printing out a " << m.size() << " x " << m.size()
            << " matrix:" << std::endl;
  for (auto row : m) {
    for (auto e : row) {
      std::cout << e << " ";
    }
    std::cout << std::endl;
  }
}
