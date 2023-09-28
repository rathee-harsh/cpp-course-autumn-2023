#include "dragon_cave.hpp"

// Define DragonCave's methods here
std::ostream& operator<<(std::ostream& os, const DragonCave& cave) {
  os << "DragonCave dwellers:" << std::endl << std::endl;
  for (auto it = cave.dragons_.begin(); it != cave.dragons_.end(); it++) {
    os << *it;
    if (std::next(it) != cave.dragons_.end()) {
      os << std::endl;
    }
  }
  return os;
}