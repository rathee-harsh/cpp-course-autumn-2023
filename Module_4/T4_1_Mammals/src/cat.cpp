#include "cat.hpp"

const std::string& Cat::GetName() const { return name_; }
std::string Cat::MakeSound() { return "Meow"; }