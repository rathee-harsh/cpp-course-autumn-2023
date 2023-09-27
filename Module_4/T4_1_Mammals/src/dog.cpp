#include "dog.hpp"

const std::string& Dog::GetName() const { return name_; }
std::string Dog::MakeSound() { return "Wuff!"; }