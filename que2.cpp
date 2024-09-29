#include <iostream>
#include <string>
using namespace std;

class Per_son {
public:
    string name;
    string room;
    string phone;


    // here is a Constructor
    Per_son() {}

    Per_son(string n, string p, string r) : name(n), phone(p), room(r) {}

    // this Function to display details
    void displayDetails() const {
        cout << "Name: " << name<<endl<< " Phone: " << phone<<endl << "Room: " << room << endl;
    }
};

// Class representing a department
class Depart_ment {
private:
    Per_son head;          // head is for HOD
    Per_son faculty[5];    // faculty is for Faculty members including the head
    Per_son admin;         // Administrative officer


public:
    // Constructor
    Depart_ment(Per_son h, Per_son a, Per_son f[5]) : head(h), admin(a) {
        int i = 0;
        while (i < 5) {
            faculty[i] = f[i];
            i++;
        }
    }

    // a Function to find a person by name within the given department
    Per_son* findPerson(const string& name) {
        if (head.name == name) return &head;
        if (admin.name == name) return &admin;
        int i = 0;
        while (i < 5) {
            if (faculty[i].name == name) return &faculty[i];
            i++;
        }
        return nullptr;
    }

    // Function to get the head and admin details
    Per_son* getHead() { return &head; }
    Per_son* getAdmin() { return &admin; }
};

// Class representing the administration which manages multiple departments
class Administration {
private:
    Depart_ment* departments[6]; // Array of department pointers

public:
    // Constructor that initializes all the departments
    Administration() {
        // CSE Department
        Per_son hodCSE("Sambuddho Chakravarty", "011-26907478", "B-503 (R&D Block)");
        Per_son adminCSE("Vinayak Abrol", "011-26907543", "A-409 (R&D Block)");
        Per_son facultyCSE[5] = {
            Per_son("Debajyoti Bera", "011-26907442", "B-508 (R&D Block)"),
            Per_son("Arani Bhattacharya", "011-26907434", "B-510 (R&D Block)"),
            Per_son("Pankaj Jalote", "011-26907499", "A-705 (R&D Block)"),
            Per_son("Bapi Chatterjee", "011-26907371", "B-402 (R&D Block)"),
            Per_son("Sambuddho Chakravarty", "011-26907478", "B-503 (R&D Block)")
        };
        departments[0] = new Depart_ment(hodCSE, adminCSE, facultyCSE);

        // ECE Department
        Per_son hodECE("A V Subramanyam", "+91 011-26907437", "B-604 (R&D Block)");
        Per_son adminECE("Vinayak Abrol", "011-26907543", "A-409 (R&D Block)");
        Per_son facultyECE[5] = {
            Per_son("Sujay Deb", "011-26907452", "A-607 (R&D Block)"),
            Per_son("Pravesh Biyani", "011-26907449", "A-604 (R&D Block)"),
            Per_son("Abhijit Mitra", "+91 011-26907450", "B-605 (R&D Block)"),
            Per_son("Pragya Kosta", "011-26907491", "B-607 (R&D Block)"),
            Per_son("Ranjan Bose", "011-26907481", "A-707 (R&D Block)")
        };
        departments[1] = new Depart_ment(hodECE, adminECE, facultyECE);

        // CB Department
        Per_son hodCB("G P S Raghava", "011-26907444", "A-302 (R&D Block)");
        Per_son adminCB("Vinayak Abrol", "011-26907543", "A-409 (R&D Block)");
        Per_son facultyCB[5] = {
            Per_son("G P S Raghava", "011-26907444", "A-302 (R&D Block)"),
            Per_son("Tarini Shankar Ghosh", "011-26907375", "A-312 (R&D Block)"),
            Per_son("Gaurav Ahuja", "011-26907475", "A-303 (R&D Block)"),
            Per_son("Tavpritesh Sethi", "011 26907 533", "A-309 (R&D Block)"),
            Per_son("N. Arul Murugan", "011-26907372", "A-311 (R&D Block)")
        };
        departments[2] = new Depart_ment(hodCB, adminCB, facultyCB);

        // CSD Department
        Per_son hodCSD("Richa Gupta", "011-26907368", "A-406 (R&D Block)");
        Per_son adminCSD("Vinayak Abrol", "011-26907543", "A-409 (R&D Block)");
        Per_son facultyCSD[5] = {
            Per_son("Richa Gupta", "011-26907368", "A-406 (R&D Block)"),
            Per_son("Pragma Kar", "011-26907450", "A-411 (R&D Block)"),
            Per_son("Sonal Keshwani", "011-26907521", "A-405 (R&D Block)"),
            Per_son("Anmol Srivastava", "011-26907467", "A-404 (R&D Block)"),
            Per_son("Arun Balaji Buduru", "011-26907469", "B-504 (R&D Block)")
        };
        departments[3] = new Depart_ment(hodCSD, adminCSD, facultyCSD);

        // CSAM Department
        Per_son hodCSAM("Kaushik Kalyanaraman", "011-26907537", "B-302 (R&D Block)");
        Per_son adminCSAM("Vinayak Abrol", "011-26907543", "A-409 (R&D Block)");
        Per_son facultyCSAM[5] = {
            Per_son("Kaushik Kalyanaraman", "011-26907537", "B-302 (R&D Block)"),
            Per_son("Nabanita Ray", "011-26907464", "B-312 (R&D Block)"),
            Per_son("Sneha Chaubey", "011-26907462", "B-308 (R&D Block)"),
            Per_son("Manuj Mukherjee", "011-26907376", "A-608 (R&D Block)"),
            Per_son("Prahllad Deb", "011-26907551", "B-305 (R&D Block)")
        };
        departments[4] = new Depart_ment(hodCSAM, adminCSAM, facultyCSAM);

        // CSSH Department
        Per_son hodCSSH("Kiriti Kanjilal", "011-26907558", "B-208 (R&D Block)");
        Per_son adminCSSH("Vinayak Abrol", "011-26907543", "A-409 (R&D Block)");
        Per_son facultyCSSH[5] = {
            Per_son("Kiriti Kanjilal", "011-26907558", "B-208 (R&D Block)"),
            Per_son("Deepak Prince", "011-26907595", "A-210 (R&D Block)"),
            Per_son("J. V. Meenakshi", "011-26907535", "B-205 (R&D Block)"),
            Per_son("Aasim Khan", "011-26907463", "B-202 (R&D Block)"),
            Per_son("Manohar Kumar", "011-26907557", "B-207 (R&D Block)")
        };
        departments[5] = new Depart_ment(hodCSSH, adminCSSH, facultyCSSH);
    }

    // Destructor to clean up dynamically allocated departments
    ~Administration() {
        int i = 0;
        while (i < 6) {
            delete departments[i];
            i++;
        }
    }

    // Function to fetch details of a person by name across all departments
    Per_son* getPersonDetails(const string& name) {
        int i = 0;
        while (i < 6) {
            Per_son* person = departments[i]->findPerson(name);
            if (person != nullptr) {
                return person;
            }
            i++;
        }
        return nullptr; // Person not found
    }

    // Function to fetch head or admin details by their name
    Per_son* getAdminOrHeadDetails(const string& name) {
        int i = 0;
        while (i < 6) {
            if (departments[i]->getHead()->name == name) {
                return departments[i]->getHead();
            }
            if (departments[i]->getAdmin()->name == name) {
                return departments[i]->getAdmin();
            }
            i++;
        }
        return nullptr; // Not found
    }
};

int main() {
    // now Create an Administration instance which initializes all departments
    Administration admin;

    string name_to_search;
    char choice;

    do {
        cout << "Please Enter the name of the person you want to search: ";
        getline(cin, name_to_search);

        // Check for person in faculty, HOD, and admin
        Per_son* person = admin.getPersonDetails(name_to_search);
        if (person != nullptr) {
            person->displayDetails();  // Display the person's details if the given person found
        } else {
            // Check for head or admin details
            person = admin.getAdminOrHeadDetails(name_to_search);
            if (person != nullptr) {
                person->displayDetails();  
            } else {
                cout << "Person you are searching not found in the administration structure." << endl;
            }
        }

        cout << "\nDo you want to search for another person? (Y/N): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        cout << endl;

    } while (choice == 'Y' || choice == 'y');

    cout << "Exiting the program. Goodbye!" << endl;
    return 0; // End of program
}