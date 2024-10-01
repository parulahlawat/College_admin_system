#include <iostream>
#include <fstream>
#include <sstream>
#include "Library.h"
#include "functions.h"

using namespace std;

int main() {
    Library library;

    // Load journals from file
    ifstream journalFile("journals.csv");
    if (journalFile.is_open()) {
        string line;
        while (getline(journalFile, line)) {
            string fields[2];
            splitLine(line, fields, 2);

            Journals *journal = new Journals(0, fields[0]);
            library.addItem(journal);
        }
        journalFile.close();
    }

    // Load books from file
    ifstream bookFile("books.csv");
    if (bookFile.is_open()) {
        string line;
        getline(bookFile, line); // Skip header
        while (getline(bookFile, line)) {
            string fields[24];
            splitCSVLine(line, fields, 24);

            int book_id = stoi(fields[0]);
            int isbn = stoi(fields[5]);
            string authors = fields[7];
            int publication_year = stoi(fields[8]);
            string title = fields[9];

            Book *book = new Book(0, book_id, isbn, title, authors, publication_year);
            library.addItem(book);
        }
        bookFile.close();
    }

    // Main menu
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Register as a Student" << endl;
        cout << "2. Register as a Teacher" << endl;
        cout << "3. Search for a Book" << endl;
        cout << "4. Borrow a Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string userName;
                cout << "Enter your name: ";
                cin.ignore();
                getline(cin, userName);
                library.registerUser(userName, false); // Register student
                break;
            }
            case 2: {
                string userName;
                cout << "Enter your name: ";
                cin.ignore();
                getline(cin, userName);
                library.registerUser(userName, true); // Register teacher
                break;
            }
            case 3: {
                string searchType;
                cout << "Search by (author/title): ";
                cin >> searchType;

                if (searchType == "author") {
                    string author;
                    cout << "Enter author name: ";
                    cin.ignore();
                    getline(cin, author);
                    Book *matchingBooks[100];
                    int matchingCount = 0;
                    library.searchBooksByAuthor(author, matchingBooks, matchingCount);
                    for (int i = 0; i < matchingCount; ++i) {
                        matchingBooks[i]->printDetails();
                    }
                } else if (searchType == "title") {
                    string title;
                    cout << "Enter title: ";
                    cin.ignore();
                    getline(cin, title);
                    Book *matchingBooks[100];
                    int matchingCount = 0;
                    library.searchBooksByTitle(title, matchingBooks, matchingCount);
                    for (int i = 0; i < matchingCount; ++i) {
                        matchingBooks[i]->printDetails();
                    }
                }
                break;
            }
            case 4: {
                string userName;
                int bookId;
                cout << "Enter your name: ";
                cin.ignore();
                getline(cin, userName);
                cout << "Enter book ID: ";
                cin >> bookId;
                library.borrowBook(userName, bookId);
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:                 cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
            
            