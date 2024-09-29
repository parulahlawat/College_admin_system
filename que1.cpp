#include <iostream>
#include <string>
#include <limits> // Include this header for numeric_limits

using namespace std;

const int MAX_PERSONNEL = 30; // Maximum number of personnel per department

class Person {
public:
    string name;
    string designation;
    string email;
    string phone;
    string room;

    Person() = default;

    Person(const string& n, const string& d, const string& e, const string& p, const string& r)
        : name(n), designation(d), email(e), phone(p), room(r) {}
};

class AdminDepartment {
protected:
    Person personnel[MAX_PERSONNEL];
    int personnelCount;

public:
    AdminDepartment() : personnelCount(0) {}

    virtual void addPerson(const Person& person) {
        if (personnelCount < MAX_PERSONNEL) {
            personnel[personnelCount++] = person;
        } else {
            cout << "Error: Maximum personnel limit reached in this department." << endl;
        }
    }

    virtual void printPersonnel() const {
        for (int i = 0; i < personnelCount; ++i) {
            cout << "Name: " << personnel[i].name
                 << ", Designation: " << personnel[i].designation
                 << ", Email: " << personnel[i].email
                 << ", Phone: " << personnel[i].phone
                 << ", Room: " << personnel[i].room << endl;
        }
    }

    virtual Person* findPersonByName(const string& name) {
        for (int i = 0; i < personnelCount; ++i) {
            if (personnel[i].name == name) {
                return &personnel[i];
            }
        }
        return nullptr;
    }
};

class I_R_D_Department : public AdminDepartment {
public:
    I_R_D_Department() : AdminDepartment() {}
};

class Acad_emics_Dept : public AdminDepartment {
public:
    Acad_emics_Dept() : AdminDepartment() {}
};

class Student_Affairs_Depart_ment : public AdminDepartment {
public:
    Student_Affairs_Depart_ment() : AdminDepartment() {}
};

class StorePurchase : public AdminDepartment {
public:
    StorePurchase() : AdminDepartment() {}
};

class Library : public AdminDepartment {
public:
    Library() : AdminDepartment() {}
};

void findAndDisplayContactInfo(AdminDepartment* departments[], int numDepartments, const string& name) {
    for (int i = 0; i < numDepartments; ++i) {
        Person* person = departments[i]->findPersonByName(name);
        if (person) {
            cout<< "\nContact Information for " << name << ":" << endl;
            cout<< "Designation: " << person->designation << endl;
            cout<< "Room: " << person->room << endl;
            cout<< "Phone: " << person->phone << endl;
            cout<< "Email: " << person->email << endl;
            return;
        }
    }
    cout << "\nPerson not found." << endl;
}

int main() {
    const int numDepartments = 5;
    I_R_D_Department I_R_D_Department;
    Acad_emics_Dept acad_emics_Dept;
    Student_Affairs_Depart_ment studentAffairsDepartment;
    StorePurchase storePurchaseDepartment;
    Library libraryDepartment;

    AdminDepartment* departments[numDepartments] = {
        &I_R_D_Department,
        &acad_emics_Dept,
        &studentAffairsDepartment,
        &storePurchaseDepartment,
        &libraryDepartment
    };

    // Add personnel to I_R_D_Department (only those with "Innovation, Research & Development" or "IRD" in their designation)
    I_R_D_Department.addPerson(Person("Vivek Ashok Bohara", "Dean of Innovation, Research & Development", "dird@iiitd.ac.in", "91-11-26907454", "Not Provided"));
    I_R_D_Department.addPerson(Person("Debarka Sengupta", "Associate Dean of Innovation, Research & Development", "adird@iiitd.ac.in", "91-11-26907446", "Not Provided"));
    I_R_D_Department.addPerson(Person("Kapil Dev Garg", "Administrative Officer (IRD)", "kapil.garg@iiitd.ac.in", "011 26907 454", "Room A-306, Academic Block"));
    I_R_D_Department.addPerson(Person("Imran Khan", "Junior Administrative Officer (IRD) (SG)", "imran@iiitd.ac.in", "011 26907 454", "Room A-307, Academic Block"));

    // Add personnel to Acad_emics_Dept
    acad_emics_Dept.addPerson(Person("Sumit J Darak", "Dean of Academic Affairs", "doaa@iiitd.ac.in", "91-11-26907427", "Not Provided"));
    acad_emics_Dept.addPerson(Person("Anshu Dureja", "Deputy Administrative Officer (Academics)", "anshu@iiitd.ac.in", "011 26907 135", "Room B-208, Academic Block"));
    acad_emics_Dept.addPerson(Person("Ashutosh Brahma", "Administrative Officer (Academics)", "ashutosh@iiitd.ac.in", "011 26907 135", "Room B-202, Academic Block"));
    acad_emics_Dept.addPerson(Person("Akanksha", "Junior Administrative Officer (Academics)", "akanksha@iiitd.ac.in", "011 26907 135", "Room B-207, Academic Block"));
    acad_emics_Dept.addPerson(Person("Ashish Aggarwal", "Junior Administrative Officer (Academics)", "ashish@iiitd.ac.in", "011 26907 135", "Room B-207, Academic Block"));
    acad_emics_Dept.addPerson(Person("Aakash Gupta", "Junior Administrative Officer (Academics)", "aakash@iiitd.ac.in", "011 26907 135", "Room B-207, Academic Block"));
    acad_emics_Dept.addPerson(Person("Mohit Kumar", "Junior Administrative Officer (Academics)", "mohit@iiitd.ac.in", "011 26907 135", "Room B-208, Academic Block"));
    acad_emics_Dept.addPerson(Person("Nisha Narwal", "Assistant Administrative Officer (Academics) (SG)", "nisha@iiitd.ac.in", "011 26907 135", "Room B-207, Academic Block"));
    acad_emics_Dept.addPerson(Person("Prachi Mukherjee", "Assistant Administrative Officer (Academics) (SG)", "prachi@iiitd.ac.in", "011 26907 135", "Room B-207, Academic Block"));
    acad_emics_Dept.addPerson(Person("Raju Biswas", "Junior Administrative Officer (Academics)", "raju@iiitd.ac.in", "011 26907 135", "Room B-208, Academic Block"));
    acad_emics_Dept.addPerson(Person("Sanjana Soni", "Junior Administrative Officer (Academics)", "sanjana@iiitd.ac.in", "011 26907 135", "Room B-207, Academic Block"));
    acad_emics_Dept.addPerson(Person("Sudhanshu Tamta", "Junior Administrative Officer (Academics) (SG)", "sudhanshut@iiitd.ac.in", "011 26907 565", "Room No. B-207 (Academic Block)"));

    // Add personnel to Student Affairs
    studentAffairsDepartment.addPerson(Person("Shobha Sundar Ram", "Dean of Student Affairs", "dosa@iiitd.ac.in", "91-11-26907460", "Not Provided"));
    studentAffairsDepartment.addPerson(Person("Dr. Ravi Bhasin", "Administrative Officer (Student Affairs)", "ravi@iiitd.ac.in", "011 26907 460", "Room A-207-1, Academic Block"));
    studentAffairsDepartment.addPerson(Person("Jagadanand Dwivedi", "Junior Administrative Officer (Student Affairs) (SG)", "jagadanand@iiitd.ac.in", "011 26907 460", "Room A-207-1, Academic Block"));
    studentAffairsDepartment.addPerson(Person("Sonal Garg", "Junior Administrative Officer (Student Affairs) (SG)", "sonal@iiitd.ac.in", "011 26907 577", "Room No. A-207-1 (Academic Block)"));
    studentAffairsDepartment.addPerson(Person("Khushpinder Pal Sharma", "Counselling Psychologist", "khushpinder@iiitd.ac.in", "011 26907 460", "Room A-206, Academic Block"));

    // Add personnel to Store & Purchase
    storePurchaseDepartment.addPerson(Person("Ajay Kumar", "Administrative Officer (Store & Purchase)", "ajay@iiitd.ac.in", "011 26907 561", "Room A-103(2), Academic Block"));
    storePurchaseDepartment.addPerson(Person("Nidhi Yadav", "Assistant Administrative Officer (Store & Purchase) (SG)", "nidhi@iiitd.ac.in", "011 26907 561", "Room A-108, Academic Block"));
    storePurchaseDepartment.addPerson(Person("Sangam Kumar Yadav", "Junior Administrative Officer (Store & Purchase)", "sangam@iiitd.ac.in", "011 26907 561", "Room A-106, Academic Block"));

    // Add personnel to Library
    libraryDepartment.addPerson(Person("Rajendra Singh", "Library Officer (SG)", "rajendra@iiitd.ac.in", "011-26907510", "Library Block"));
    libraryDepartment.addPerson(Person("Parikshita Behera", "Junior Library Officer", "parikshita@iiitd.ac.in", "011-26907503", "Library Block"));

    string name;
    char choice;

    do {
        cout << "Enter name to get contact information: ";
        getline(cin, name);
        findAndDisplayContactInfo(departments, numDepartments, name);

        cout << "\nDo you want to search for another person? (Y/N): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        cout << endl;

    } while (choice == 'Y' || choice == 'y');

    cout << "Exiting the program. Goodbye!" << endl;
    return 0;
}