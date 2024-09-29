# College_admin_systemProject Overview

This is a simple C++ program that reads contact details from a CSV file and searches for a person’s contact information based on their name. It handles various fields such as name, designation, email, phone number, and room number, ensuring that the room number is formatted correctly and the data is displayed up to the second comma, if applicable.

The program is capable of handling CSV files with fields that contain commas, especially when those fields are enclosed in double quotes.

How It Works

The program reads a CSV file where each line contains the contact details of a person in the following format:
name,designation,email,phone,room
The program prompts the user to enter the name of the person they are searching for.
	•	It then scans the CSV file to find the matching name and prints the relevant contact information.
	•	If the room field contains multiple commas, the program stops displaying after the second comma to ensure proper formatting.

Key Features

	•	Trim Function: Removes leading and trailing whitespace from the strings.
	•	readField Function: Reads individual fields from the CSV file, handling quoted fields that may contain commas. If a field is enclosed in double quotes ("), the function reads the entire field, even if it contains commas inside.
	•	extractRoomData Function: Ensures that the room field is displayed correctly. If the room field contains multiple commas, the function extracts the part before the second comma and ignores the rest.
	•	findContact Function: Searches for the person by name in the CSV file and prints their contact details if found. If the person is not found, an appropriate message is displayed.

How to Run the Program

	1.	Prepare the CSV File: Ensure that the CSV file you want to read is formatted correctly and contains the following columns in order:
	•	Name
	•	Designation
	•	Email
	•	Phone
	•	Room
Example CSV content: John Doe,"Dean of Innovation, Research & Development",john@example.com,1234567890,"Room A-123, Office Block, IIITD Campus"
Jane Smith,Professor,jane@example.com,0987654321,"Room B-234, R&D Block"
    2.	Compile and Run the Program:
	•	Compile the program using a C++ compiler.

    3.	Input: The program will prompt you to enter the name of the person whose contact details you want to find. You can enter the name or type exit to quit.
Example interaction:
Enter the name of the person to get contact details (or type 'exit' to quit): John Doe

Output: The program will display the contact details of the person if found:
Contact details for John Doe:
Designation: Dean of Innovation, Research & Development
Email: john@example.com
Phone: 1234567890
Room: Room A-123

File Structure
.
├── contact_finder.cpp  # Main program file
└── iiitd_administration.csv  # Example CSV file with contact details

Dependencies

	•	C++11 or higher
	•	A valid CSV file with correctly formatted contact details
References

	•	“The C++ Programming Language (4th Edition)” by Bjarne Stroustrup
A comprehensive guide to C++ programming, covering language features and standard libraries.
	•	“C++ Primer (5th Edition)” by Stanley B. Lippman, Josée Lajoie, and Barbara E. Moo
An excellent resource for understanding C++ concepts, including string manipulation and file I/O.
	•	Stack Overflow
https://stackoverflow.com
A community-driven Q&A site used for troubleshooting and finding code examples related to CSV parsing and string handling. also used some online AI tools


# Question2

Overview

The Administration Management System is a console-based C++ application designed to manage and search personnel details across multiple departments within an organization. The system allows users to search for individuals by name, retrieving their contact information and room assignments. It encompasses various roles, including Heads of Departments (HOD), administrative officers, and faculty members.

Features

	•	Department Management: Handles multiple departments, each with its own HOD, administrative officer, and faculty members.
	•	Search Functionality: Enables searching for individuals across all departments by name.
	•	Dynamic Data Handling: Utilizes dynamic memory allocation to manage department instances.
	•	User Interaction: Provides a user-friendly interface for inputting search queries and navigating the system.
	•	Modular Design: Implements object-oriented principles for scalability and maintainability.

Class Structure

Per_son Class

Represents an individual within the organization, encapsulating their personal details.

	•	Attributes:
	•	name: The full name of the person.
	•	phone: Contact phone number.
	•	room: Room or office location.
	•	Constructors:
	•	Default Constructor: Initializes an empty Per_son object.
	•	Parameterized Constructor: Initializes a Per_son object with specified name, phone, and room.
	•	Methods:
	•	displayDetails(): Displays the person’s details in a formatted manner.

Depart_ment Class

Represents a department within the organization, managing its HOD, administrative officer, and faculty members.

	•	Attributes:
	•	head: The Head of Department (HOD).
	•	admin: The Administrative Officer.
	•	faculty[5]: An array of Per_son objects representing faculty members, including the HOD.
	•	Constructor:
	•	Initializes the department with specified HOD, administrative officer, and faculty members.
	•	Methods:
	•	findPerson(const string& name): Searches for a person by name within the department.
	•	getHead(): Retrieves the HOD’s details.
	•	getAdmin(): Retrieves the Administrative Officer’s details.

Administration Class

Manages multiple departments, facilitating the initialization and search operations across all departments.

	•	Attributes:
	•	departments[6]: An array of pointers to Depart_ment objects, representing different departments.
	•	Constructor:
	•	Initializes all departments with their respective HODs, administrative officers, and faculty members.
	•	Destructor:
	•	Cleans up dynamically allocated memory for departments to prevent memory leaks.
	•	Methods:
	•	getPersonDetails(const string& name): Searches for a person across all departments.
	•	getAdminOrHeadDetails(const string& name): Retrieves details if the person is a HOD or administrative officer.

References

The development of this Administration Management System leverages standard C++ programming practices and object-oriented principles. also used some AI tools .Below are some references and resources that provide foundational knowledge and guidance used in crafting this application:

	1.	C++ Documentation:
	•	C++ Reference
	•	C++ Programming Language
	2.	Object-Oriented Programming (OOP) in C++:
	•	GeeksforGeeks - OOP Concepts
	•	TutorialsPoint - C++ OOP
	3.	Dynamic Memory Management in C++:
	•	GeeksforGeeks - Dynamic Memory Allocation
	•	cplusplus.com - New and Delete
	4.	C++ Best Practices:
	•	ISO C++ Best Practices
	•	GeeksforGeeks - C++ Best Practices
	5.	Error Handling in C++:
	•	C++ Exception Handling
	6.	Standard Template Library (STL):
	•	C++ STL Tutorial
	•	cplusplus.com - STL


# Question 3

Features

	•	Dual Complaint Categories: Users can file complaints under either “Administrative” or “Academic” categories.
	•	Department Management: Supports multiple departments within both administrative and academic realms.
	•	Escalation Matrix: Automatically escalates complaints based on the number of days since the complaint was raised.
	•	Dynamic Department Listing: Displays all available departments when filing an administrative complaint to guide users.
	•	Seniority-Based Escalation: Escalates complaints through personnel based on their seniority levels.

Architecture

The system is structured using several classes, each responsible for different aspects of the complaint management and escalation process.

Classes

Per_son

Purpose: Stores individual details such as name, office, and phone number.

Attributes:

	•	string name;
	•	string office;
	•	string phone;

Constructors:

	•	Default constructor.
	•	Parameterized constructor to initialize all attributes.

D_ept

Purpose: Represents an academic department, managing its Head of Department (HOD), faculty members, and administrative officer.

Attributes:

	•	Per_son hod;
	•	Per_son faculty[5];
	•	Per_son adminOfficer;

Methods:

	•	void escalateComplaint(int days);
	•	Prints the escalation matrix based on the number of days since the complaint was raised.

Administration

Purpose: Manages all academic departments and handles academic complaints.

Attributes:

	•	D_ept* departments[6]; // Array of pointers to departments

Methods:

	•	void handleComplaint(const string& dept, int days);
	•	Identifies the department based on user input and triggers the escalation process.

Constructor:

	•	Initializes all six departments with their respective HODs, administrative officers, and faculty members.

Destructor:

	•	Frees allocated memory for departments.

Person_1

Purpose: Represents an administrative personnel involved in handling administrative complaints.

Attributes:

	•	string department;
	•	string pos_ton; // Position title
	•	string name;

Constructors:

	•	Parameterized constructor to initialize all attributes.

ComplaintEscalationSystem

Purpose: Manages administrative personnel and handles administrative complaints, including escalation based on seniority levels.

Attributes:

	•	Person_1* peo_ple[MAX_PEOPLE];
	•	int peopleCount;

Methods:

	•	int getSeniorityLevel(const string& pos_ton);
	•	Determines the seniority level of a position title.
	•	Person_1* getLowestLevelPerson(const string& department);
	•	Finds the lowest-level person in a specified department.
	•	void escalateComplaint1(const string& department, const string& complainant, int daysPassed);
	•	Manages the escalation of complaints based on the number of days since they were raised.
	•	void printDepartments(); (Added in a previous update)
	•	Prints all available administrative departments for user reference.

Constructor:

	•	Initializes the array of administrative personnel with their respective departments and positions.

Destructor:

	•	Frees allocated memory for administrative personnel.

Compilation

To compile the program, ensure you have a C++ compiler installed (e.g., g++). Follow these steps:

	1.	Save the Code:
	•	Save the provided C++ code in a file named complaint_system.cpp.
	2.	Open Terminal:
	•	Navigate to the directory containing complaint_system.cpp.

Usage

	1.	Start the Program:
	•	Upon running, the program prompts the user to choose the type of complaint.
	2.	Choose Complaint Type:
	•	Enter either Administrative or Academic.
	3.	Administrative Complaint Flow:
	•	List of Departments: The program displays all available administrative departments.
	•	Enter Department: Input the desired department from the list.
	•	Enter Complainant Name: Provide the name of the person raising the complaint.
	•	Enter Days Passed: Specify the number of days since the complaint was raised.
	•	Escalation: The program displays the escalation path based on the input.
	4.	Academic Complaint Flow:
	•	Enter Department: Input the department code (e.g., CSE, ECE, CB, etc.).
	•	Enter Days Passed: Specify the number of days since the complaint was raised.
	•	Escalation: The program displays the escalation matrix for academic complaints.
	5.	Invalid Input Handling:
	•	If an invalid complaint type or department is entered, the program notifies the user accordingly.

References

	•	“The C++ Programming Language (4th Edition)” by Bjarne Stroustrup
A comprehensive guide to C++ programming, covering language features and standard libraries.
	•	“C++ Primer (5th Edition)” by Stanley B. Lippman, Josée Lajoie, and Barbara E. Moo
An excellent resource for understanding C++ concepts, including string manipulation and file I/O.
	•	Stack Overflow
https://stackoverflow.com
A community-driven Q&A site used for troubleshooting and finding code examples related to CSV parsing and string handling. also used some online AI tools

