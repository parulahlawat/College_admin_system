#include "Library.h"
#include "Book.h"
#include "Journals.h"
#include "PublicationRank.h"
#include <iostream>
#include <algorithm>
#include <cctype>

// Function to convert a string to lowercase for case-insensitive searching
std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

// Search for books by the author's name
void Library::searchBooksByAuthor(const std::string &bookAuthor, Book *matchingBooks[], int &matchingCount) {
    matchingCount = 0;
    std::string searchAuthorLower = toLowerCase(bookAuthor);

    for (int i = 0; i < itemCount; i++) {
        Book *book = dynamic_cast<Book *>(libraryItems[i]);
        if (book) {
            std::string bookAuthorLower = toLowerCase(book->getAuthors());
            if (bookAuthorLower.find(searchAuthorLower) != std::string::npos) {
                matchingBooks[matchingCount++] = book; // Found a book with a matching author name
            }
        }
    }
}

// Search for books by the title
void Library::searchBooksByTitle(const std::string &bookTitle, Book *matchingBooks[], int &matchingCount) {
    matchingCount = 0;
    std::string searchTitleLower = toLowerCase(bookTitle);

    for (int i = 0; i < itemCount; i++) {
        Book *book = dynamic_cast<Book *>(libraryItems[i]);
        if (book) {
            std::string bookTitleLower = toLowerCase(book->getTitle());
            if (bookTitleLower.find(searchTitleLower) != std::string::npos) {
                matchingBooks[matchingCount++] = book; // Found a book with a matching title
            }
        }
    }
}

// Search for publications by name
void Library::searchPublication(const std::string &publicationName, PublicationRank *matchingPublications[], int &matchingCount) {
    matchingCount = 0;
    std::string searchPubLower = toLowerCase(publicationName);

    for (int i = 0; i < itemCount; i++) {
        PublicationRank *publication = dynamic_cast<PublicationRank *>(libraryItems[i]);
        if (publication) {
            std::string pubNameLower = toLowerCase(publication->getPublication());
            if (pubNameLower.find(searchPubLower) != std::string::npos) {
                matchingPublications[matchingCount++] = publication; // Found a publication with a matching name
            }
        }
    }
}

// Search for journals by title
void Library::searchJournal(const std::string &journalTitle, Journals *matchingJournals[], int &matchingCount) {
    matchingCount = 0;
    std::string searchTitleLower = toLowerCase(journalTitle);

    for (int i = 0; i < itemCount; i++) {
        Journals *journal = dynamic_cast<Journals *>(libraryItems[i]);
        if (journal) {
            std::string journalTitleLower = toLowerCase(journal->getTitle());
            if (journalTitleLower.find(searchTitleLower) != std::string::npos) {
                matchingJournals[matchingCount++] = journal; // Found a journal with a matching title
            }
        }
    }
}

// Borrow a book
bool Library::borrowBook(const std::string &userName, int bookIdToBorrow) {
    User *user = findUserByName(userName);
    if (!user) {
        std::cout << "User not found." << std::endl;
        return false;
    }

    Book *bookToBorrow = dynamic_cast<Book *>(findItemById(bookIdToBorrow));
    if (!bookToBorrow || bookToBorrow->isBorrowed()) {
        std::cout << "Book not available." << std::endl;
        return false;
    }

    if (!user->canBorrowMoreBooks()) {
        std::cout << userName << " has reached the maximum number of borrowed books." << std::endl;
        return false;
    }

    bookToBorrow->setBorrowed(true);
    user->borrowBook(bookToBorrow);
    std::cout << userName << " has borrowed the book: " << bookToBorrow->getTitle() << std::endl;
    return true;
}

// Borrow a journal
bool Library::borrowJournal(const std::string &userName, int journalIdToBorrow) {
    User *user = findUserByName(userName);
    if (!user) {
        std::cout << "User not found." << std::endl;
        return false;
    }

    Journals *journalToBorrow = dynamic_cast<Journals *>(findItemById(journalIdToBorrow));
    if (!journalToBorrow) {
        std::cout << "Journal not available." << std::endl;
        return false;
    }

    user->borrowJournal(journalToBorrow);
    std::cout << userName << " has borrowed the journal: " << journalToBorrow->getTitle() << std::endl;
    return true;
}

// Helper function to find a user by name (case-insensitive)
User* Library::findUserByName(const std::string &userName) {
    std::string lowerName = toLowerCase(userName);
    for (int i = 0; i < studentCount; i++) {
        if (toLowerCase(students[i].getName()) == lowerName) {
            return &students[i];
        }
    }
    for (int i = 0; i < teacherCount; i++) {
        if (toLowerCase(teachers[i].getName()) == lowerName) {
            return &teachers[i];
        }
    }
    return nullptr;
}

// Helper function to find an item by ID
LibraryItem* Library::findItemById(int id) {
    for (int i = 0; i < itemCount; i++) {
        if (libraryItems[i]->getID() == id) {
            return libraryItems[i];
        }
    }
    return nullptr;
}