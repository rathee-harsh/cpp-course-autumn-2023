#include "library.hpp"

#include <iostream>

#include "book.hpp"
#include "customer.hpp"

Library::Library(const std::string& name) { name_ = name; }
std::string Library::GetName() const { return name_; }
std::vector<Book>& Library::GetBooks() { return books_; }
std::vector<Customer>& Library::GetCustomers() { return customers_; }
Book Library::FindBookByName(const std::string& name) {
  for (auto book : books_) {
    if (book.GetName() == name) {
      return book;
    }
  }
  Book b = Book("", "", "");
  return b;
}
std::vector<Book> Library::FindBooksByAuthor(const std::string& name) {
  std::vector<Book> books;
  for (auto book : books_) {
    if (book.GetAuthor() == name) {
      books.push_back(book);
    }
  }
  return books;
}

std::vector<Book> Library::FindAllLoanedBooks() {
  std::vector<Book> books;
  for (auto book : books_) {
    if (book.GetStatus()) {
      books.push_back(book);
    }
  }
  return books;
}