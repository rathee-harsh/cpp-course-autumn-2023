#include "register.hpp"

#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

#include "aircraft.hpp"
#include "boat.hpp"
#include "vehicle.hpp"
// TODO: implement Register's members
Register::~Register() {}

void Register::Add(Vehicle* v) { vehicles_.push_back(v); }
void Register::Save(const std::string& filename) const {
  std::ofstream os(filename);
  for (auto vehicle : vehicles_) {
    (*vehicle).Write(os);
    os << std::endl;
  }
  os.close();
}
bool Register::ReadLine(std::istream& stream) {
  std::string line;
  std::getline(stream, line);
  std::stringstream ss;
  ss.str(line);
  if (line[0] == 'A') {
    Aircraft* a = Aircraft::Read(ss);
    if (a != NULL) {
      Add(a);
      return true;
    }
  } else if (line[0] == 'B') {
    Boat* b = Boat::Read(ss);
    if (b != NULL) {
      Add(b);
      return true;
    }
  }
  return false;
}

int Register::Load(const std::string& filename) {
  std::ifstream istr(filename);
  int n = 0;
  if (istr.rdstate() & (istr.failbit | istr.badbit)) {
    // output error to stderr stream
    std::cerr << "Failed" << std::endl;
    return -1;
  } else {
    while (!istr.eof()) {
      if (ReadLine(istr)) {
        n += 1;
      }
    }
  }
  return n;
}

void Register::Print() {
  for (auto vehicle : vehicles_) {
    (*vehicle).Print();
  }
}

size_t Register::Size() const { return vehicles_.size(); }