#include "Journals.h"
#include <iostream>

// Constructor
Journals::Journals(int ID, const std::string &title) : ID(ID), title(title) {}

// Getter for ID
int Journals::getID() const {
    return ID;
}

// Getter for title
std::string Journals::getTitle() const {
    return title;
}

// Print journal details
void Journals::printDetails() const {
    std::cout << "ID: " << ID << "\nJournal Title: " << title << "\n";
}