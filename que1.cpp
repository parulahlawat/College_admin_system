#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Function to trim spaces from both ends of a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

// Function to read a field from the CSV file, handling quoted fields
std::string readField(std::istringstream& ss) {
    std::string field;
    char ch;

    if (ss.peek() == '"') {
        // Quoted field, read until the closing quote
        ss.get(ch); // Consume the initial quote
        while (ss.get(ch)) {
            if (ch == '"') {
                if (ss.peek() == '"') {
                    // Double quote within the field, treat as a literal quote
                    field += '"';
                    ss.get(ch);
                } else {
                    // End of the quoted field
                    break;
                }
            } else {
                field += ch;
            }
        }
        // Consume the comma after the closing quote
        ss.get(ch); // This should be the comma separating fields
    } else {
        // Unquoted field, read until the next comma
        std::getline(ss, field, ',');
    }

    return trim(field);
}

// Function to extract room data, stopping before the second comma
std::string extractRoomData(const std::string& room) {
    size_t firstComma = room.find(',');
    if (firstComma == std::string::npos) {
        // No commas in the room string, return it as is
        return room;
    }

    // Find the second comma
    size_t secondComma = room.find(',', firstComma + 1);
    if (secondComma != std::string::npos) {
        // Return the substring up to the second comma
        return room.substr(0, secondComma);
    }

    // If there's only one comma, return the substring up to that comma
    return room;
}

// Function to find and print contact details
void findContact(const std::string& filePath, const std::string& searchName) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    std::string line;
    bool contactFound = false;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string name, designation, email, phone, room;

        // Read name, designation, email, phone, and room, handling quoted fields
        name = readField(ss);
        designation = readField(ss);
        email = readField(ss);
        phone = readField(ss);
        room = readField(ss);  // Room field might contain commas

        // Check if the name matches the search query
        if (name == searchName) {
            std::cout << "Contact details for " << searchName << ":\n";
            std::cout << "Designation: " << designation << std::endl;
            std::cout << "Email: " << email << std::endl;
            std::cout << "Phone: " << phone << std::endl;

            // Print room data, stopping at the second comma
            std::cout << "Room: " << extractRoomData(room) << std::endl;

            contactFound = true;
            break; // Stop after finding the contact, preventing further printing
        }
    }

    if (!contactFound) {
        std::cerr << "Contact not found." << std::endl;
    }

    file.close();
}

int main() {
    std::string filePath = "/Users/parulahlawat/Downloads/iiitd_administration.csv";
    
    while (true) {
        std::string searchName;
        std::cout << "\nEnter the name of the person to get contact details (or type 'exit' to quit): ";
        std::getline(std::cin, searchName);

        if (searchName == "exit") {
            break;
        }

        findContact(filePath, searchName);
    }

    return 0;
}