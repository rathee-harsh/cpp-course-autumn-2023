#include "aircraft.hpp"
// TODO: implement Aircraft's members
Aircraft::Aircraft(std::string register_number, std::string owner,
                   std::string model, double wingspan,
                   unsigned int cruise_speed)
    : Vehicle(register_number, owner),
      model_(model),
      wingspan_(wingspan),
      cruise_speed_(cruise_speed) {}

void Aircraft::Write(std::ostream& stream) {
  stream << "A;" << GetRegisterNumber() << ";" << GetOwner() << ";" << model_
         << ";" << wingspan_ << ";" << cruise_speed_ << std::endl;
}

void Aircraft::Print() { Write(std::cout); }

Aircraft* Aircraft::Read(std::istream& stream) {
  std::string i, register_number, owner, model, wingspan, cruise_speed;
  if (std::getline(stream, i, ';') &&
      std::getline(stream, register_number, ';') &&
      std::getline(stream, owner, ';') && std::getline(stream, model, ';') &&
      std::getline(stream, wingspan, ';') &&
      std::getline(stream, cruise_speed, ';') && i == "A") {
    try {
      float ws = std::stof(wingspan);
      unsigned int cs = std::stoul(cruise_speed);
      return new Aircraft(register_number, owner, model, ws, cs);
    } catch (...) {
      return NULL;
    }
  }
  return NULL;
}