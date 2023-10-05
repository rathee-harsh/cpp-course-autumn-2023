#include "boat.hpp"
// TODO: implement Boat's members
Boat::Boat(std::string register_number, std::string owner, std::string name,
           double draft, double power)
    : Vehicle(register_number, owner),
      name_(name),
      draft_(draft),
      power_(power) {}

void Boat::Write(std::ostream& stream) {
  stream << "B;" << GetRegisterNumber() << ";" << GetOwner() << ";" << name_
         << ";" << draft_ << ";" << power_ << std::endl;
}

void Boat::Print() { Write(std::cout); }

Boat* Boat::Read(std::istream& stream) {
  std::string i, register_number, owner, name, draft, power;
  if (std::getline(stream, i, ';') &&
      std::getline(stream, register_number, ';') &&
      std::getline(stream, owner, ';') && std::getline(stream, name, ';') &&
      std::getline(stream, draft, ';') && std::getline(stream, power, ';') &&
      i == "B") {
    try {
      double d = std::stod(draft);
      double p = std::stod(power);
      return new Boat(register_number, owner, name, d, p);
    } catch (...) {
      return NULL;
    }
  }
  return NULL;
}