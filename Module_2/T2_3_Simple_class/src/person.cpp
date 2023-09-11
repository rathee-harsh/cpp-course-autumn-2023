#include "person.hpp"

// define your Person class' functions here

Person::Person(const std::string& name, int birthyear)
    : name_(name), birthyear_(birthyear) {}

const std::string& Person::GetName() const { return name_; }

int Person::GetAge(int year) const { return year - birthyear_; }