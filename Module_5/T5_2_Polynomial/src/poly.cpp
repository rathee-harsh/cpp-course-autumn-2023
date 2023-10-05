#include "poly.hpp"

#include <sstream>

int Poly::operator[](int exp) const {
  auto it = values_.find(exp);
  return it == values_.end() ? 0 : it->second;
}

Poly operator-(const Poly& p) {
  Poly p2;
  for (auto i = p.begin(); i != p.end(); i++) {
    p2[i->first] = -i->second;
  }
  return p2;
}

Poly& Poly::operator+=(const Poly& b) {
  if (b.values_.size() > values_.size()) {
    auto i = begin();
    for (auto j = b.begin(); j != b.end(); j++) {
      if (i != end()) {
        values_[i->first] = i->second + j->second;
        i++;
      } else {
        values_.insert(j->first, j->second);
      }
    }
  } else {
    auto i = b.begin();
    for (auto j = begin(); j != end(); j++) {
      if (i != end()) {
        values_[j->first] = i->second + j->second;
        i++;
      }
    }
  }
  return *this;
}

Poly& Poly::operator-=(const Poly& b) {
  return *this += -b;
  //   if (b.values_.size() > values_.size()) {
  //     auto i = begin();
  //     for (auto j = b.begin(); j != b.end(); j++) {
  //       if (i != end()) {
  //         values_[i->first] = i->second - j->second;
  //         i++;
  //       } else {
  //         values_.insert(j->first, j->second);
  //       }
  //     }
  //   } else {
  //     auto i = b.begin();
  //     for (auto j = begin(); j != end(); j++) {
  //       if (i != end()) {
  //         values_[j->first] = -i->second + j->second;
  //         i++;
  //       }
  //     }
  //   }
  //   return *this;
}

Poly operator+(const Poly& a, const Poly& b) {
  auto j = b.begin();
  Poly p;
  for (auto i = a.begin(); i != a.end(); i++) {
    if (j != b.end()) {
      p[i->first] = j->second + i->second;
      j++;
    } else {
      p[i->first] = i->second;
    }
  }
  if (j != b.end()) {
    for (auto k = j; k != b.end(); k++) {
      p[k->first] = k->second;
    }
  }
  return p;
}

Poly operator-(const Poly& a, const Poly& b) { return a + (-b); }

bool operator<(const Poly& a, const Poly& b) {
  return a.cend()->first < b.cend()->first;
}

bool operator==(const Poly& a, const Poly& b) {
  return a.cend()->first == b.cend()->first;
}

bool operator>(const Poly& a, const Poly& b) {
  return a.cend()->first > b.cend()->first;
}

bool operator!=(const Poly& a, const Poly& b) {
  return a.cend()->first != b.cend()->first;
}

std::ostream& operator<<(std::ostream& os, const Poly& p) {
  for (auto i = p.rbegin(); i != p.rend(); i++) {
    if (i->first != 0) {
      os << i->first << "x" << i->second;
    }
    if (i != p.rend()--) {
      os << "+";
    }
  }
  return os;
}
std::istream& operator>>(std::istream& is, Poly& p) {
  // repeat until end of file
  while (!is.eof()) {
    // read a line from file, output it to screen
    std::string line;
    std::getline(is, line, '+');
    int s = line.find('x');
    std::string coe = line.substr(0, s);
    std::string exp = line.substr(s + 1);
    int c = stoi(coe);
    int e = stoi(exp);
    p[e] = c;
  }
  return is;
}