#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Base class Person
class Person {
protected:
    string name;
    string roomNumber;
    string phoneNumber;
    string email;

public:
    Person(string name, string room, string phone, string email)
        : name(name), roomNumber(room), phoneNumber(phone), email(email) {}

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Room: " << roomNumber << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    string getName() {
        return name;
    }
};

// Derived classes
class Registrar : public Person {
public:
    Registrar(string name, string room, string phone, string email)
        : Person(name, room, phone, email) {}
};

class Dean : public Person {
public:
    Dean(string name, string room, string phone, string email)
        : Person(name, room, phone, email) {}
};

class AssociateDean : public Person {
public:
    AssociateDean(string name, string room, string phone, string email)
        : Person(name, room, phone, email) {}
};

// Directory Class
class Directory {
private:
    unordered_map<string, Person*> directory;

public:
    // Add person to the directory
    void addPerson(Person* p) {
        directory[p->getName()] = p;
    }

    // Search for a person by name
    void searchPerson(string name) {
        if (directory.find(name) != directory.end()) {
            directory[name]->displayInfo();
        } else {
            cout << "Person not found in the directory." << endl;
        }
    }
};

// Main function
int main() {
    Directory adminDirectory;

    // Adding people to the directory
    Person* registrar = new Registrar("John Doe", "Room 101", "1234567890", "johndoe@iiitd.ac.in");
    Person* dean = new Dean("Jane Smith", "Room 102", "0987654321", "janesmith@iiitd.ac.in");
    Person* associateDean = new AssociateDean("Emily Davis", "Room 103", "5555555555", "emilydavis@iiitd.ac.in");

    adminDirectory.addPerson(registrar);
    adminDirectory.addPerson(dean);
    adminDirectory.addPerson(associateDean);

    // Search for a person
    string searchName;
    cout << "Enter the name of the person to search: ";
    getline(cin, searchName);

    adminDirectory.searchPerson(searchName);

    // Cleanup
    delete registrar;
    delete dean;
    delete associateDean;

    return 0;
}