#include "aviary.hpp"

void Aviary::Add(Bird* bird) { birds_.push_back(bird); }

void Aviary::SpeakAll(std::ostream& os) const {
  for (auto it : birds_) {
    it->Speak(os);
  }
}

Bird* Aviary::operator[](size_t idx) {
  if (idx >= this->Size()) {
    throw std::out_of_range("blah");
  }
  auto l_front = birds_.begin();
  std::advance(l_front, idx);
  return *(l_front);
}

const Bird* Aviary::operator[](size_t idx) const {
  if (idx >= this->Size()) {
    throw std::out_of_range("blah");
  }
  auto l_front = birds_.begin();
  std::advance(l_front, idx);
  return (const Bird*)*(l_front);
}

Aviary::~Aviary() {
  for (auto it : birds_) {
    delete it;
  }
}