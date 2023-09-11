#include <string>

#ifndef AALTO_ELEC_CPP_PERSON
#define AALTO_ELEC_CPP_PERSON

// declare your Person class here
class Person {
 public:
  Person(const std::string& name, int birthyear);
  const std::string& GetName() const;
  int GetAge(int year) const;

 private:
  std::string name_;
  int birthyear_;
};

#endif