#include "Book.h"
#include <iostream>

// Constructor
Book::Book(int id, int isbn, const std::string& title, const std::string& authors, int year)
    : bookId(id), isbn(isbn), title(title), authors(authors), publicationYear(year) {}

// Print book details
void Book::printDetails() const {
    std::cout << "Book ID: " << bookId
              << "\nTitle: " << title
              << "\nAuthors: " << authors
              << "\nISBN: " << isbn
              << "\nPublication Year: " << publicationYear << std::endl;
}