#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Base class for all administrative members
class AdminMember {
protected:
    string name;
    string email;
    string phone;
    string room;

public:
    AdminMember(string nm, string em, string ph, string rm) 
        : name(nm), email(em), phone(ph), room(rm) {}

    virtual void displayContactDetails() {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
        cout << "Room: " << room << endl;
    }

    string getName() const {
        return name;
    }
};

// Derived class for Deans and Associate Deans
class Dean : public AdminMember {
protected:
    string designation;

public:
    Dean(string nm, string em, string ph, string rm, string desig) 
        : AdminMember(nm, em, ph, rm), designation(desig) {}

    void displayContactDetails() override {
        cout << "Designation: " << designation << endl;
        AdminMember::displayContactDetails();
    }
};

// Derived class for the Registrar
class Registrar : public AdminMember {
public:
    Registrar(string nm, string em, string ph, string rm) 
        : AdminMember(nm, em, ph, rm) {}

    void displayContactDetails() override {
        cout << "Role: Registrar" << endl;
        AdminMember::displayContactDetails();
    }
};

// Administrative structure that manages contacts
class AdminStructure {
private:
    unordered_map<string, AdminMember*> adminMembers;

public:
    void addMember(string name, AdminMember* member) {
        adminMembers[name] = member;
    }

    void getContactDetails(string name) {
        if (adminMembers.find(name) != adminMembers.end()) {
            adminMembers[name]->displayContactDetails();
        } else {
            cout << "No contact details found for " << name << endl;
        }
    }

    ~AdminStructure() {
        for (auto &member : adminMembers) {
            delete member.second; // Free allocated memory
        }
    }
};

// Main function to test the administrative structure
int main() {
    AdminStructure adminStructure;

    // Adding members to the structure
    adminStructure.addMember("Pankaj Vajpayee", 
        new Dean("Pankaj Vajpayee", "dcre@iiitd.ac.in", "91-11-26907515", "Not Provided", "Dean of Corporate Relations & Entrepreneurship"));
    
    adminStructure.addMember("Sanjit Krishnan Kaul", 
        new Dean("Sanjit Krishnan Kaul", "adofa@iiitd.ac.in", "91-11-26907457", "Not Provided", "Associate Dean of Faculty Affairs"));
    
    adminStructure.addMember("Registrar", 
        new Registrar("Prof. Ranjan Bose", "bose@iiitd.ac.in", "91-11-26907481", "A-707, R & D Block"));

    // Main function for user input to fetch contact details
    string queryName;
    cout << "Enter the name of the person to get contact details: ";
    getline(cin, queryName); // Get input from the user

    // Fetch and display the contact details
    adminStructure.getContactDetails(queryName);

    return 0;
}