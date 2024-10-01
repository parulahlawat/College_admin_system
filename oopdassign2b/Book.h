#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include "LibraryItem.h"

class Book : public LibraryItem {
private:
    int ID;
    int book_id;
    int isbn;
    std::string title;
    std::string authors;
    int original_publication_year;
    bool borrowed;

public:
    Book() : book_id(0), isbn(0), title(""), authors(""), original_publication_year(0), borrowed(false) {}
    Book(int ID, int book_id, int isbn, const std::string &title, const std::string &authors, int original_publication_year)
        : ID(ID), book_id(book_id), isbn(isbn), title(title), authors(authors), original_publication_year(original_publication_year), borrowed(false) {}

    int getID() const { return ID; }
    int getBookID() const { return book_id; }
    int getISBN() const { return isbn; }
    std::string getTitle() const { return title; }
    std::string getAuthors() const { return authors; }
    int getPublicationYear() const { return original_publication_year; }
    bool isBorrowed() const { return borrowed; }
    
    void setID(int id) { ID = id; }
    void setBookID(int bookid) { book_id = bookid; }
    void setISBN(int Isbn) { isbn = Isbn; }
    void setTitle(const std::string &newTitle) { title = newTitle; }
    void setAuthors(const std::string &newAuthors) { authors = newAuthors; }
    void setPublicationYear(int year) { original_publication_year = year; }
    void setBorrowed(bool status) { borrowed = status; }

    void printDetails() const override {
        std::cout << "ID: " << ID << "\nBook_id: " << book_id << "\nISBN: " << isbn
                  << "\nTitle: " << title << "\nAuthors: " << authors << "\nPublication Year: " << original_publication_year << "\n";
    }
};

#endif // BOOK_H