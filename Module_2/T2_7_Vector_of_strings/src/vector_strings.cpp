#include "vector_strings.hpp"

#include <iostream>
#include <string>
#include <vector>

void Adder(std::vector<std::string>& names) {
  std::cout << "Enter a name:" << std::endl;
  std::string name;
  std::cin >> name;
  names.push_back(name);
  std::cout << "Number of names in the vector:" << std::endl
            << names.size() << std::endl;
}

void Remover(std::vector<std::string>& names) {
  std::string name = names[names.size() - 1];
  names.pop_back();
  std::cout << "Removing the last element:" << std::endl << name << std::endl;
}

void Printer(std::vector<std::string>& names) {
  for (unsigned int i = 0; i < names.size(); i++) {
    std::cout << names[i] << std::endl;
  }
}

void CMDReader() {
  std::vector<std::string> names;
  while (true) {
    std::cout << "Commands: ADD, PRINT, REMOVE, QUIT" << std::endl
              << "Enter a command:" << std::endl;
    std::string command;
    std::cin >> command;
    if (command == "ADD") {
      Adder(names);
    } else if (command == "PRINT") {
      Printer(names);
    } else if (command == "REMOVE") {
      Remover(names);
    } else if (command == "QUIT") {
      return;
    }
  }
}
