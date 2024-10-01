#ifndef PUBLICATIONRANK_H
#define PUBLICATIONRANK_H

#include "LibraryItem.h"
#include <string>

class PublicationRank : public LibraryItem {
private:
    int ID;
    std::string publication;
    int rank;
    double totalPaid;
    bool borrowed;

public:
    // Constructor
    PublicationRank(int ID, const std::string &publication, int rank, double totalPaid);

    // Getters
    int getID() const;
    std::string getPublication() const;
    int getRank() const;
    double getTotalPaid() const;
    bool isBorrowed() const;

    // Setter for borrowing status
    void setBorrowed(bool status);

    // Print publication details
    void printDetails() const override;
};

#endif // PUBLICATIONRANK_H