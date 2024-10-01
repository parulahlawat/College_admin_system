#ifndef USER_H
#define USER_H

#include <string>
#include <ctime>
#include "Book.h"

class User {
private:
    std::string name;
    bool isTeacher;
    static const int MAX_BORROWED_BOOKS = 3; // Maximum number of books a user can borrow
    int borrowedCount;

public:
    Book *borrowedBooks[MAX_BORROWED_BOOKS];
    time_t borrowedDates[MAX_BORROWED_BOOKS];

    // Default constructor
    User() : name(""), isTeacher(false), borrowedCount(0) {
        for (int i = 0; i < MAX_BORROWED_BOOKS; ++i) {
            borrowedBooks[i] = nullptr;
        }
    }

    // Parameterized constructor
    User(const std::string &name, bool isTeacher) : name(name), isTeacher(isTeacher), borrowedCount(0) {
        for (int i = 0; i < MAX_BORROWED_BOOKS; ++i) {
            borrowedBooks[i] = nullptr;
        }
    }

    std::string getName() const {
        return name;
    }

    bool isTeacherUser() const {
        return isTeacher;
    }

    int getBorrowedCount() const {
        return borrowedCount;
    }

    int getMaxBorrowedBooks() const {
        return MAX_BORROWED_BOOKS;
    }

    void incrementBorrowedCount() {
        borrowedCount++;
    }

    bool canBorrowMoreBooks() const {
        return borrowedCount < MAX_BORROWED_BOOKS;
    }

    time_t getLastBorrowTime(const Book *book) const {
        for (int i = 0; i < MAX_BORROWED_BOOKS; ++i) {
            if (borrowedBooks[i] == book) {
                return borrowedDates[i];
            }
        }
        return 0;
    }

    void setLastBorrowTime(const Book *book, time_t borrowTime) {
        for (int i = 0; i < MAX_BORROWED_BOOKS; ++i) {
            if (borrowedBooks[i] == book) {
                borrowedDates[i] = borrowTime;
                return;
            }
        }
    }
};

#endif // USER_H