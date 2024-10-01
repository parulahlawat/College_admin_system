#include "PublicationRank.h"
#include <iostream>

// Constructor
PublicationRank::PublicationRank(int ID, const std::string &publication, int rank, double totalPaid)
    : ID(ID), publication(publication), rank(rank), totalPaid(totalPaid), borrowed(false) {}

// Getter for ID
int PublicationRank::getID() const {
    return ID;
}

// Getter for publication name
std::string PublicationRank::getPublication() const {
    return publication;
}

// Getter for rank
int PublicationRank::getRank() const {
    return rank;
}

// Getter for total paid
double PublicationRank::getTotalPaid() const {
    return totalPaid;
}

// Check if publication is borrowed
bool PublicationRank::isBorrowed() const {
    return borrowed;
}

// Set the borrowing status
void PublicationRank::setBorrowed(bool status) {
    borrowed = status;
}

// Print publication details
void PublicationRank::printDetails() const {
    std::cout << "ID: " << ID << "\nPublication: " << publication
              << "\nRank: " << rank << "\nTotal Paid: " << totalPaid
              << "\nBorrowed: " << (borrowed ? "Yes" : "No") << "\n";
}