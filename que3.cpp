#include <iostream>
#include <string>

using namespace std;

// Here the Per_son class to store individual details
class Per_son {
public:
    string name;
    string office;
    string phone;

    Per_son() {}

    Per_son(string n, string p, string o)
        : name(n), phone(p), office(o) {}
};

// D_ept class to store academic department details
class D_ept {
private:
    Per_son hod;
    Per_son faculty[5];
    Per_son adminOfficer;

public:
    D_ept() {}

    D_ept(Per_son h, Per_son a, Per_son f[])
        : hod(h), adminOfficer(a) {
        int i = 0;
        while (i < 5) {
            faculty[i] = f[i];
            i++;
        }
    }

    
    void escalateComplaint(int days) {
        cout << "Escalation Matrix:\n";

        if (days <= 3) {
            cout << "1. NOW Contact Faculty Member: " << faculty[0].name << endl;
        }
        else if (days <= 6) {
            cout << "1. Contact Faculty Member: " << faculty[0].name << endl;
            cout << "2. Escalate to HOD: " << hod.name << endl;
        }
        else {
            cout << "1. Contact Faculty Member: " << faculty[0].name << endl;
            cout << "2. Escalate to HOD: " << hod.name << endl;
            cout << "3. Escalate to Admin Officer: " << adminOfficer.name << endl;
        }
    }
};

// Administration class to store departments
class Administration {
private:
    D_ept* departments[6]; // Array of department pointers

public:
    // Constructor that initializes all the departments
    Administration() {
        // CSE Department
        Per_son hodCSE("Sambuddho Chakravarty", "011-26907478", "B-503 (R&D Block)");
        Per_son adminCSE("Vinayak Abrol", "011-26907543", "-409 (R&D Block)");
        Per_son facultyCSE[5] = {
            Per_son("Arani Bhattacharya", "011-26907434", "B-510 (R&D Block)"),
            Per_son("Debajyoti Bera", "011-26907442", "B-508 (R&D Block)"),
            Per_son("Pankaj Jalote", "011-26907499", "A-705 (R&D Block)"),
            Per_son("Ravi Anand", "011-26907466", "A-503 (R&D Block)"),
            Per_son("Sambuddho Chakravarty", "011-26907478", "B-503 (R&D Block)")
        };
        departments[0] = new D_ept(hodCSE, adminCSE, facultyCSE);

        // ECE Department
        Per_son hodECE("A V Subramanyam", "+91 011-26907437", "B-604 (R&D Block)");
        Per_son adminECE("Vinayak Abrol", "011-26907543", "-409 (R&D Block)");
        Per_son facultyECE[5] = {
            Per_son("Angshul", "011-26907451", "A-606 (R&D Block)"),
            Per_son("A V Subramanyam", "+91 011-26907437", "B-604 (R&D Block)"),
            Per_son("Pragya Kosta", "011-26907491", "B-607 (R&D Block)"),
            Per_son("Pravesh Biyani", "011-26907449", "A-604 (R&D Block)"),
            Per_son("Ranjan Bose", "011-26907481", "A-707 (R&D Block)")
        };
        departments[1] = new D_ept(hodECE, adminECE, facultyECE);

        // CB Department
        Per_son hodCB("G P S Raghava", "011-26907444", "A-302 (R&D Block)");
        Per_son adminCB("Vinayak Abrol", "011-26907543", "-409 (R&D Block)");
        Per_son facultyCB[5] = {
            Per_son("Arjun Ray", "011-26907438", "A-310 (R&D Block)"),
            Per_son("N. Arul Murugan", "01126907372", "A-311 (R&D Block)"),
            Per_son("G P S Raghava", "011-26907444", "A-302 (R&D Block)"),
            Per_son("Gaurav Ahuja", "011-26907475", "A-303 (R&D Block)"),
            Per_son("Tavpritesh Sethi", "011 26907 533", "A-309 (R&D Block)")
        };
        departments[2] = new D_ept(hodCB, adminCB, facultyCB);

        // CSD Department
        Per_son hodCSD("Richa Gupta", "011-26907368", "A-406 (R&D Block)");
        Per_son adminCSD("Vinayak Abrol", "011-26907543", "-409 (R&D Block)");
        Per_son facultyCSD[5] = {
            Per_son("Pragma Kar", "011-26907450", "A-411 (R&D Block)"),
            Per_son("Anmol Srivastava", "011-26907467", "A-404 (R&D Block)"),
            Per_son("Sonal Keshwani", "011-26907521", "A-405 (R&D Block)"),
            Per_son("Richa Gupta", "011-26907368", "A-406 (R&D Block)"),
            Per_son("Arun Balaji Buduru", "011-26907469", "B-504 (R&D Block)")
        };
        departments[3] = new D_ept(hodCSD, adminCSD, facultyCSD);

        // CSAM Department
        Per_son hodCSAM("Kaushik Kalyanaraman", "011-26907537", "B-302 (R&D Block)");
        Per_son adminCSAM("Vinayak Abrol", "011-26907543", "-409 (R&D Block)");
        Per_son facultyCSAM[5] = {
            Per_son("Manuj Mukherjee", "011-26907376", "A-608 (R&D Block)"),
            Per_son("Kaushik Kalyanaraman", "011-26907537", "B-302 (R&D Block)"),
            Per_son("Sneha Chaubey", "011-26907462", "B-308 (R&D Block)"),
            Per_son("Nabanita Ray", "011-26907464", "B-312 (R&D Block)"),
            Per_son("Prahllad Deb", "011-26907551", "B-305 (R&D Block)")
        };
        departments[4] = new D_ept(hodCSAM, adminCSAM, facultyCSAM);

        // CSSH Department
        Per_son hodCSSH("Kiriti Kanjilal", "011-26907558", "B-208 (R&D Block)");
        Per_son adminCSSH("Vinayak Abrol", "011-26907543", "-409 (R&D Block)");
        Per_son facultyCSSH[5] = {
            Per_son("Aasim Khan", "011-26907463", "B-202 (R&D Block)"),
            Per_son("Deepak Prince", "011-26907595", "A-210 (R&D Block)"),
            Per_son("Kiriti Kanjilal", "011-26907558", "B-208 (R&D Block)"),
            Per_son("J. V. Meenakshi", "011-26907535", "B-205 (R&D Block)"),
            Per_son("Manohar Kumar", "011-26907557", "B-207 (R&D Block)")
        };
        departments[5] = new D_ept(hodCSSH, adminCSSH, facultyCSSH);
    }

    void handleComplaint(const string& dept, int days) {
        int index = -1;

        if (dept == "CSE") index = 0;
        else if (dept == "ECE") index = 1;
        else if (dept == "CB") index = 2;
        else if (dept == "CSD") index = 3;
        else if (dept == "CSAM") index = 4;
        else if (dept == "CSSH") index = 5;

        if (index != -1) {
            departments[index]->escalateComplaint(days);
        }
        else {
            cout << "Department not found!" << endl;
        }
    }

    ~Administration() {
        int i = 0;
        while (i < 6) {
            delete departments[i];
            i++;
        }
    }
};

// Changed Person1 to Person_1
class Person_1 {
public:
    string department;
    string pos_ton;
    string name;

    Person_1(string dept, string n, string pos_ton) : department(dept), name(n), pos_ton(pos_ton) {}
};

const int MAX_PEOPLE = 50;

// Changed all instances of Person1 to Person_1
class ComplaintEscalationSystem {
private:
    Person_1* peo_ple[MAX_PEOPLE];
    int peopleCount;

    int getSeniorityLevel(const string& pos_ton) {
        if (pos_ton == "Dean" || pos_ton == "Registrar") return 4;
        if (pos_ton == "Controller of Finance" || pos_ton == "Head, Career Services") return 3;
        if (pos_ton == "Associate Dean" || pos_ton == "Administrative Officer" || pos_ton == "Executive Engineer" ||
            pos_ton == "Deputy Administrative Officer" || pos_ton == "Technical Officer" || pos_ton == "Library Officer") return 2;
        if (pos_ton == "Assistant Administrative Officer" || pos_ton == "Junior Administrative Officer" ||
            pos_ton == "Assistant Technical Officer" || pos_ton == "Counselling Psychologist" || pos_ton == "Junior Library Officer") return 1;
        return 0;
    }

public:
    ComplaintEscalationSystem() : peopleCount(0) {
        peo_ple[peopleCount++] = new Person_1("Innovation, Research & Development", "Debarka Sengupta", "Associate Dean");
        peo_ple[peopleCount++] = new Person_1("Innovation, Research & Development", "Vivek Ashok Bohara", "Dean");
        peo_ple[peopleCount++] = new Person_1("Innovation, Research & Development", "Imran Khan", "Junior Administrative Officer");
        peo_ple[peopleCount++] = new Person_1("Innovation, Research & Development", "Kapil Dev Garg", "Administrative Officer");
        peo_ple[peopleCount++] = new Person_1("Student Affairs", "Shobha Sundar Ram", "Dean");
        peo_ple[peopleCount++] = new Person_1("Student Affairs", "Dr. Ravi Bhasin", "Administrative Officer");
        peo_ple[peopleCount++] = new Person_1("Student Affairs", "Jagadanand Dwivedi", "Administrative Officer");

        peo_ple[peopleCount++] = new Person_1("Academics", "Anshu Dureja", "Administrative Officer");
        peo_ple[peopleCount++] = new Person_1("Academics", "Akanksha", "Junior Administrative Officer");
        peo_ple[peopleCount++] = new Person_1("Academics", "Mohit Kumar", "Junior Administrative Officer");
        peo_ple[peopleCount++] = new Person_1("Academics", "Raju Biswas", "Junior Administrative Officer");
        peo_ple[peopleCount++] = new Person_1("Academics", "Ashutosh Brahma", "Administrative Officer");
        peo_ple[peopleCount++] = new Person_1("Academics", "Sumit J Darak", "Dean");
        peo_ple[peopleCount++] = new Person_1("Academics", "Sudhanshu Tamta", "Junior Administrative Officer");
        peo_ple[peopleCount++] = new Person_1("Store & Purchase", "Ajay Kumar", "Administrative Officer");
        peo_ple[peopleCount++] = new Person_1("Store & Purchase", "Nidhi Yadav", "Assistant Administrative Officer");
        peo_ple[peopleCount++] = new Person_1("Store & Purchase", "Sangam Kumar Yadav", "Junior Administrative Officer");
        peo_ple[peopleCount++] = new Person_1("Library", "Rajendra Singh", "Library Officer");
        peo_ple[peopleCount++] = new Person_1("Library", "Parikshita Behera", "Junior Library Officer");

        peo_ple[peopleCount++] = new Person_1("Research", "Abhijeet Mishra", "Assistant Technical Officer");
        peo_ple[peopleCount++] = new Person_1("Research", "Khagendra Joshi", "Assistant Technical Officer");
        peo_ple[peopleCount++] = new Person_1("Research", "Sana Ali Naqvi", "Assistant Technical Officer");
        peo_ple[peopleCount++] = new Person_1("Alumni Relationship", "Deepali Gupta", "Junior Administrative Officer");

        peo_ple[peopleCount++] = new Person_1("Communication and Alumni Affairs", "Sonia Baloni Ray", "Dean");
        peo_ple[peopleCount++] = new Person_1("Academic Affairs", "Sumit J Darak", "Dean");
        peo_ple[peopleCount++] = new Person_1("Registrar", "Dr. Deepika Bhaskar", "Registrar");
    }

    Person_1* getLowestLevelPerson(const string& department) {
        Person_1* lowestPerson = nullptr;
        int lowestLevel = 5; 

        int i = 0;
        while (i < peopleCount) {
            if (peo_ple[i]->department == department) {
                int currentLevel = getSeniorityLevel(peo_ple[i]->pos_ton);
                if (currentLevel < lowestLevel) {
                    lowestLevel = currentLevel;
                    lowestPerson = peo_ple[i];
                }
            }
            i++;
        }

        return lowestPerson; 
    }

    void escalateComplaint1(const string& department, const string& complainant, int daysPassed) {
        if (daysPassed < 3) {
            cout << "The complaint has been raised for less than 3 days." << endl;
            cout << "Complaint held by: " << complainant << endl;

            Person_1* lowestPerson = getLowestLevelPerson(department);

            if (lowestPerson != nullptr) {
                cout << "Lowest level person in " << department << ": "
                     << lowestPerson->name << " (" << lowestPerson->pos_ton << ")" << endl;
            }
            else {
                cout << "No people found in department: " << department << "." << endl;
            }

            cout << "No escalation required yet." << endl;
            return;
        }

        Person_1* escalationPath[MAX_PEOPLE];
        int pathIndex = 0;

        Person_1* currentPerson = nullptr;

        int i = 0;
        while (i < peopleCount) {
            if (peo_ple[i]->department == department) {
                if (currentPerson == nullptr) {
                    currentPerson = peo_ple[i];
                }
                else {
                    if (getSeniorityLevel(peo_ple[i]->pos_ton) > getSeniorityLevel(currentPerson->pos_ton)) {
                        escalationPath[pathIndex++] = currentPerson;
                        currentPerson = peo_ple[i];
                    }
                }
            }
            i++;
        }

        // Add the highest person to the escalation path
        if (currentPerson != nullptr) {
            escalationPath[pathIndex++] = currentPerson;
        }

        // Display the entire escalation path
        if (pathIndex > 0) {
            cout << "Escalation Path for the complaint in " << department << ":" << endl;
            int j = 0;
            while (j < pathIndex - 1) {
                cout << "Escalated from " << escalationPath[j]->name << " (" << escalationPath[j]->pos_ton << ") to "
                     << escalationPath[j + 1]->name << " (" << escalationPath[j + 1]->pos_ton << ")" << endl;
                j++;
            }
            // Show the highest escalation
            cout << "Your Complaint has reached the highest level: " << escalationPath[pathIndex - 1]->name
                 << " (" << escalationPath[pathIndex - 1]->pos_ton << ")" << endl;
        }
        else {
            cout << "No people found in department: " << department << "." << endl;
        }
    }

    // Destructor to free allocated memory
    ~ComplaintEscalationSystem() {
        int i = 0;
        while (i < peopleCount) {
            delete peo_ple[i];
            i++;
        }
    }
};

int main() {
    cout << "Raise your Complaint to (Administrative / Academic): ";
    string complaintType;
    cin >> complaintType;

    if (complaintType == "Academic") {
        Administration adminSystem;

        string department;
        int days;

        cout << "Enter the department (CSE, ECE, CB, CSD, CSAM, CSSH): ";
        cin >> department;
        cout << "Enter number of days since complaint raised: ";
        cin >> days;

        adminSystem.handleComplaint(department, days);
    }
    else if (complaintType == "Administrative") {
        ComplaintEscalationSystem system;

        string department, complainant;
        int daysPassed;

        cout << "now Enter the department: ";
        cin.ignore(); 
        getline(cin, department);

        cout << "here Enter the name of the complainant: ";
        getline(cin, complainant);

        cout << "Enter the number of days since the complaint was raised: ";
        cin >> daysPassed;

        system.escalateComplaint1(department, complainant, daysPassed);
    }
    else {
        cout << "Invalid complaint type. Please choose Administrative or Academic." << endl;
    }

    return 0;
}