#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include "LibraryItem.h"
#include "Book.h"
#include "User.h"
#include "Journals.h"
#include "PublicationRank.h"

const int MAX_ITEMS = 500; // Maximum number of items in the library

class Library {
private:
    LibraryItem *libraryItems[MAX_ITEMS];
    int itemCount;
    int nextBookId;
    int totalCopies;
    
    User students[100]; // Assuming a maximum of 100 students
    int studentCount;

    User teachers[50]; // Assuming a maximum of 50 teachers
    int teacherCount;

public:
    Library();

    void addItem(LibraryItem *item);
    void addBook(int isbn, const std::string &author, const std::string &title, int originalPublicationYear);

    void registerUser(const std::string &name, bool isTeacher);

    void printAllItems() const;

    void searchBooksByAuthor(const std::string &bookAuthor, Book *matchingBooks[], int &matchingCount);
    void searchBooksByTitle(const std::string &bookTitle, Book *matchingBooks[], int &matchingCount);

    bool borrowBook(const std::string &userName, int bookIdToBorrow);
    bool returnBook(Book *book);

    bool isEqualIgnoreCase(const std::string &str1, const std::string &str2);
};

#endif // LIBRARY_H