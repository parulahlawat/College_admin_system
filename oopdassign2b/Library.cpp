#include <iostream>
#include <thread>
#include <chrono>
#include "Library.h"

Library::Library() : itemCount(0), nextBookId(1), totalCopies(5), studentCount(0), teacherCount(0) {}

// Function to add an item to the library
void Library::addItem(LibraryItem *item) {
    if (itemCount < MAX_ITEMS) {
        libraryItems[itemCount++] = item;
    } else {
        std::cout << "Library is full. Cannot add more items." << std::endl;
    }
}

// Function to add a new book to the library
void Library::addBook(int isbn, const std::string &author, const std::string &title, int originalPublicationYear) {
    if (itemCount >= MAX_ITEMS) {
        std::cout << "The library is full. Cannot add more books." << std::endl;
        return;
    }

    // Create a new Book object
    Book *newBook = new Book();
    newBook->setBookID(nextBookId++);  // Assign a unique book ID
    newBook->setISBN(isbn);            // Set the ISBN
    newBook->setAuthors(author);       // Set the author
    newBook->setTitle(title);          // Set the title
    newBook->setPublicationYear(originalPublicationYear); // Set the publication year

    addItem(newBook); // Add the book to the library
    std::cout << "Added book with ID " << newBook->getBookID() << " to the library." << std::endl;
}

// Function to register a user (student or teacher)
void Library::registerUser(const std::string &name, bool isTeacher) {
    if (isTeacher) {
        if (teacherCount < 50) {
            teachers[teacherCount++] = User(name, true);
            std::cout << "Registered as a Teacher." << std::endl;
        } else {
            std::cout << "Teacher registration full." << std::endl;
        }
    } else {
        if (studentCount < 100) {
            students[studentCount++] = User(name, false);
            std::cout << "Registered as a Student." << std::endl;
        } else {
            std::cout << "Student registration full." << std::endl;
        }
    }
    std::cout << "-------------------------" << std::endl;
}

// Function to print all items in the library
void Library::printAllItems() const {
    for (int i = 0; i < itemCount; ++i) {
        if (libraryItems[i]) {
            libraryItems[i]->printDetails();
            std::cout << "------------------------\n";
        }
    }
}

// Function to search for a book by author name
void Library::searchBooksByAuthor(const std::string &bookAuthor, Book *matchingBooks[], int &matchingCount) {
    matchingCount = 0;

    std::string searchAuthorLower = bookAuthor;
    for (char &c : searchAuthorLower) {
        c = tolower(c);
    }

    for (int i = 0; i < itemCount; ++i) {
        Book *book = dynamic_cast<Book *>(libraryItems[i]);
        if (book) {
            std::string bookAuthorLower = book->getAuthors();
            for (char &c : bookAuthorLower) {
                c = tolower(c);
            }
            if (bookAuthorLower.find(searchAuthorLower) != std::string::npos) {
                matchingBooks[matchingCount++] = book;
            }
        }
    }
}

// Function to search for a book by title
void Library::searchBooksByTitle(const std::string &bookTitle, Book *matchingBooks[], int &matchingCount) {
    matchingCount = 0;

    std::string searchTitleLower = bookTitle;
    for (char &c : searchTitleLower) {
        c = tolower(c);
    }

    for (int i = 0; i < itemCount; ++i) {
        Book *book = dynamic_cast<Book *>(libraryItems[i]);
        if (book) {
            std::string bookTitleLower = book->getTitle();
            for (char &c : bookTitleLower) {
                c = tolower(c);
            }
            if (bookTitleLower.find(searchTitleLower) != std::string::npos) {
                matchingBooks[matchingCount++] = book;
            }
        }
    }
}

// Borrow a book by its book ID
bool Library::borrowBook(const std::string &userName, int bookIdToBorrow) {
    User *user = nullptr;

    for (int i = 0; i < studentCount; ++i) {
        if (isEqualIgnoreCase(students[i].getName(), userName)) {
            user = &students[i];
            std::cout << "Registered as a Student." << std::endl;
            break;
        }
    }

    if (!user) {
        for (int i = 0; i < teacherCount; ++i) {
            if (isEqualIgnoreCase(teachers[i].getName(), userName)) {
                user = &teachers[i];
                std::cout << "Registered as a Teacher." << std::endl;
                break;
            }
        }
    }

    if (!user) {
        std::cout << "User not found." << std::endl;
        return false;
    }

    Book *bookToBorrow = nullptr;

    for (int i = 0; i < itemCount; ++i) {
        Book *book = dynamic_cast<Book *>(libraryItems[i]);
        if (book && book->getBookID() == bookIdToBorrow) {
            bookToBorrow = book;
            break;
        }
    }

    if (!bookToBorrow) {
        std::cout << "Book not found." << std::endl;
        return false;
    }

    if (!user->canBorrowMoreBooks()) {
        std::cout << userName << " has reached the maximum number of borrowed books." << std::endl;
        return false;
    }

    time_t now = time(nullptr);
    struct tm *timeinfo = localtime(&now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    std::cout << "Current local time: " << buffer << std::endl;

    int returnPeriod = (user->isTeacherUser()) ? 180 : 30; //(1 day = 1 sec)

    if (now - user->getLastBorrowTime(bookToBorrow) >= returnPeriod || !bookToBorrow->isBorrowed()) {
        if (totalCopies > 0) {
            user->borrowedBooks[user->getBorrowedCount()] = bookToBorrow;
            user->borrowedDates[user->getBorrowedCount()] = now;
            user->setLastBorrowTime(bookToBorrow, now);
            user->incrementBorrowedCount();

            bookToBorrow->setBorrowed(true);
            totalCopies--;

            std::cout << userName << " has borrowed the book: " << bookToBorrow->getTitle() << std::endl;

            std::thread returnThread([this, bookToBorrow, returnPeriod]() {
                std::this_thread::sleep_for(std::chrono::seconds(returnPeriod));
                returnBook(bookToBorrow); 
            });
            returnThread.detach(); 
            return true;
        } else {
            std::cout << "No available copies of the book." << std::endl;
            return false;
        }
    } else {
        std::cout << "The book is not available for borrowing yet." << std::endl;
        return false;
    }
}

// Return a borrowed book
bool Library::returnBook(Book *book) {
    if (book->isBorrowed()) {
        book->setBorrowed(false);
        totalCopies++;
        std::cout << "\nBook returned: " << book->getTitle() << std::endl;
        time_t now = time(nullptr);
        struct tm *timeinfo = localtime(&now);

        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        std::cout << "Current local time: " << buffer << std::endl;
        return true;
    } else {
        std::cout << "\nBook not borrowed or not found." << std::endl;
        return false;
    }
}

// Function to compare two strings case-insensitively
bool Library::isEqualIgnoreCase(const std::string &str1, const std::string &str2) {
    if (str1.size() != str2.size()) {
        return false;
    }
    for (size_t i = 0; i < str1.size(); ++i) {
        if (tolower(str1[i]) != tolower(str2[i])) {
            return false;
        }
    }
    return true;
}