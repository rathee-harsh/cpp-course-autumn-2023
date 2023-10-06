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
  *this = *this + b;
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
  Poly p;
  for (auto i = b.begin(); i != b.end(); i++) {
    p[i->first] = 0;
  }
  for (auto i = a.begin(); i != a.end(); i++) {
    p[i->first] = i->second;
  }
  for (auto i = b.begin(); i != b.end(); i++) {
    p[i->first] += i->second;
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
    if (i->second != 0) {
      if (i->second > 0 && i != p.rbegin()) {
        os << "+";
      }
      os << i->second << "x" << i->first;
    }
  }
  return os;
}

std::istream& operator>>(std::istream& is, Poly& p) {
  for (auto i = p.begin(); i != p.end(); i++) {
    p[i->first] = 0;
  }
  std::string expression;
  is >> expression;

  std::istringstream iss(expression);
  std::string term;

  while (std::getline(iss, term, '+')) {
    std::istringstream termStream(term);
    int c = 0, e = 0;

    while (std::getline(termStream, term, '-')) {
      if (!term.empty()) {
        size_t x_pos = term.find('x');

        if (x_pos != std::string::npos) {
          std::string coe_str = term.substr(0, x_pos);
          c = (coe_str.empty() || coe_str == "-") ? (coe_str == "-" ? -1 : 1)
                                                  : stoi(coe_str);

          std::string exp_str = term.substr(x_pos + 1);
          e = (exp_str.empty() || exp_str == "-") ? (exp_str == "-" ? -1 : 1)
                                                  : stoi(exp_str);
        } else {
          // If there's no 'x', it's a constant term (x^0)
          c = stoi(term);
          e = 0;
        }

        p[e] += c;
      }
    }
  }

  return is;
}

// while (std::getline(iss, termStr, '+')) {
//   std::istringstream termStream(termStr);
//   std::string token;
//   int c, e;
//   while (std::getline(termStream, token, '-')) {
//     size_t x_pos = token.find('x');
//     if (x_pos != std::string::npos) {
//       c = std::stoi(token.substr(0, x_pos));
//       size_t exp_pos = x_pos + 1;
//       if (exp_pos < token.length() && token[exp_pos] == '-') {
//         e = -std::stoi(token.substr(exp_pos + 1));
//       } else {
//         e = (exp_pos < token.length()) ? std::stoi(token.substr(exp_pos)) :
//         1;
//       }
//     } else {
//       c = std::stoi(token);
//       e = 0;
//     }

//     terms.push_back(term);
//   }
// }
// return is;

// while (!is.eof()) {
//   // read a line from file, output it to screen
//   std::string line;
//   std::getline(is, line, '+');
//   int s = line.find('x');
//   std::string coe = line.substr(0, s);
//   std::string exp = line.substr(s + 1);
//   int c = stoi(coe);
//   int e = stoi(exp);
//   p[e] = c;
// }
// return is;
// }

// // repeat until end of file
//   std::string line;
//   std::string termStr;
//   is >> line;
//   for (auto i = p.begin(); i != p.end(); i++) {
//     p[i->first] = 0;
//   }
//   std::vector<int> found_keys;
//   std::istringstream iss(line);
//   while (std::getline(iss, termStr, '-')) {
//     std::istringstream termStream(termStr);
//     std::string token;

//     while (std::getline(termStream, token, '+')) {
//       size_t x_pos = token.find('x');
//       int c, e;
//       if (x_pos != std::string::npos) {
//         c = std::stoi(token.substr(0, x_pos));
//         size_t exp_pos = x_pos + 1;
//         if (exp_pos < token.length() && token[exp_pos] == '-') {
//           e = -std::stoi(token.substr(exp_pos + 1));
//         } else {
//           e = (exp_pos < token.length()) ? std::stoi(token.substr(exp_pos)) :
//           1;
//         }
//       } else {
//         c = std::stoi(token);
//         e = 0;
//       }
//       if (std::count(found_keys.begin(), found_keys.end(), e)) {
//         p[e] += c;
//       } else {
//         p[e] = c;
//         found_keys.push_back(e);
//       }
//     }
//   }
//   return is;