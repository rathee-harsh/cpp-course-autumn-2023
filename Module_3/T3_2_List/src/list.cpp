#include "list.hpp"

#include <array>
#include <iostream>
#include <sstream>

// Implement the functions here

std::istream& GetLines(std::istream& is, std::list<std::string>& list) {
  list.clear();
  for (char line[100]; is.getline(line, 100);) {
    std::string line_str(line);
    list.push_back(line_str);
  }
  if (list.size() != 0 && list.back() == "\n") {
    list.pop_back();
  }
  return is;
}

void Print(const std::list<std::string>& list) {
  for (auto line : list) {
    std::cout << line << std::endl;
  }
}

void SortAndUnique(std::list<std::string>& list) {
  list.sort();
  list.unique();
}