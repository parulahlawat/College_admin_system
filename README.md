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