#ifndef JOURNALS_H
#define JOURNALS_H

#include "LibraryItem.h"
#include <string>

class Journals : public LibraryItem {
private:
    int ID;
    std::string title;

public:
    // Constructor
    Journals(int ID, const std::string &title);

    // Getter for ID
    int getID() const;

    // Getter for title
    std::string getTitle() const;

    // Print journal details
    void printDetails() const override;
};

#endif // JOURNALS_H