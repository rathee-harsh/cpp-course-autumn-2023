#include "dragon.hpp"

// Dragon::Dragon(const Dragon& dragon) {
//   name_ = dragon.name_;
//   age_ = dragon.age_;
//   size_ = dragon.size_;
//   for (auto it : dragon.treasures_) {
//     Treasure t = it;
//     treasures_.push_back(t);
//   }
// }

// Dragon& Dragon::operator=(const Dragon& dragon) {
//   for (auto it : treasures_) {
//     delete it;
//   }
// }

std::ostream& operator<<(std::ostream& os, const Dragon& dragon) {
  os << "Dragon named: " << dragon.name_ << ", age: " << dragon.age_
     << ", size: " << dragon.size_ << std::endl
     << "Treasures:" << std::endl;
  for (auto it : dragon.treasures_) {
    os << it.name << std::endl;
  }
  return os;
}