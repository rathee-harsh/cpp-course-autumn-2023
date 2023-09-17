#include "customer.hpp"

Customer::Customer(const std::string& name, const std::string& id) {
  name_ = name;
  id_ = id;
}

std::string Customer::GetName() const { return name_; }
std::string Customer::GetID() const { return id_; }
int Customer::GetLoanAmount() const { return (int)loans_.size(); }
std::vector<Book> Customer::GetLoans() const { return loans_; }
bool Customer::LoanBook(Book& b) {
  if (b.Loan()) {
    loans_.push_back(b);
    return true;
  }
  return false;
}
void Customer::ReturnBook(Book& b) {
  b.Restore();
  for (std::vector<Book>::iterator l = loans_.begin(); l < loans_.end(); l++) {
    if ((*l).GetISBN() == b.GetISBN()) {
      loans_.erase(l);
      return;
    }
  }
}

void Customer::Print() const {
  std::cout << "Customer: " << name_ << ", " << id_ << ", has "
            << GetLoanAmount() << " books on loan:" << std::endl;
  for (auto l : loans_) {
    l.Print();
  }
}