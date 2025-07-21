#include <iostream>
#include <iomanip>
#include <fstream> // For file handling
#include <vector>  // For storing booked rooms

// Global variables for username and password
const std::string USERNAME = "admin";
const std::string PASSWORD = "password";
const double ROOM_RATE = 100.0;  // Sample room rate

// Structure to represent a room
struct Room {
    int roomId;
    bool isReserved;
};

// Function for login
bool login() {
    std::string username, password;
    std::cout << "Welcome to Moon Hotel!\n";
    std::cout << "Please sign in to continue.\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    return (username == USERNAME && password == PASSWORD);
}

// Function to display menu and get user choice
int displayMenu() {
    std::cout << "========== Moon Hotel Menu ==========\n";
    std::cout << "1. View Rooms\n";
    std::cout << "2. Book Room\n";
    std::cout << "3. View Bookings\n";
    std::cout << "4. Prepare Bill\n";
    std::cout << "5. Help\n";
    std::cout << "6. Logout\n";
    std::cout << "7. Exit\n";
    std::cout << "=====================================\n";

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    return choice;
}

// Function to view available rooms
void viewRooms(const Room rooms[], int numRooms) {
    std::cout << "Available Rooms:\n";
    for (int i = 0; i < numRooms; ++i) {
        if (!rooms[i].isReserved) {
            std::cout << "Room ID: " << rooms[i].roomId << "\n";
        }
    }
}

// Function to book a room
void bookRoom(Room rooms[], int numRooms, std::vector<int>& bookedRooms) {
    int roomId;
    std::cout << "Enter the Room ID to book: ";
    std::cin >> roomId;

    // Assume basic validation, and the room ID exists
    rooms[roomId - 1].isReserved = true;
    bookedRooms.push_back(roomId);

    std::cout << "Room booked successfully!\n";
}

// Function to view booked rooms
void viewBookings(const std::vector<int>& bookedRooms) {
    std::cout << "Booked Rooms:\n";
    for (int roomId : bookedRooms) {
        std::cout << "Room ID: " << roomId << "\n";
    }
}

// Function to prepare a bill and save to a text file
void prepareBill(const std::vector<int>& bookedRooms) {
    double totalAmount = bookedRooms.size() * ROOM_RATE;
    std::cout << "Total Bill Amount: $" << std::fixed << std::setprecision(2) << totalAmount << "\n";

    // Save bill to a text file
    std::ofstream outFile("bill.txt");
    if (outFile.is_open()) {
        outFile << "Total Bill Amount: $" << std::fixed << std::setprecision(2) << totalAmount << "\n";
        outFile.close();
        std::cout << "Bill saved to 'bill.txt' file.\n";
    }
    else {
        std::cerr << "Unable to save bill to file.\n";
    }
}

// Function to provide help to the user
void help() {
    std::cout << "This is a Moon Hotel Management System.\n";
    std::cout << "You can view available rooms, book a room, view bookings, prepare bill, and more.\n";
    std::cout << "If you need further assistance, please contact hotel staff.\n";
}

int main() {
    bool loggedIn = login();
    if (loggedIn) {
        std::cout << "Login successful!\n";
    }
    else {
        std::cout << "Invalid username or password. Exiting...\n";
        return 1;
    }

    const int numRooms = 5;  // Number of rooms in Moon Hotel
    Room rooms[numRooms] = { {1, false}, {2, false}, {3, false}, {4, false}, {5, false} };

    std::vector<int> bookedRooms;  // Store booked room IDs

    int choice;
    do {
        choice = displayMenu();

        switch (choice) {
        case 1:
            viewRooms(rooms, numRooms);
            break;
        case 2:
            bookRoom(rooms, numRooms, bookedRooms);
            break;
        case 3:
            viewBookings(bookedRooms);
            break;
        case 4:
            prepareBill(bookedRooms);
            break;
        case 5:
            help();
            break;
        case 6:
            std::cout << "Logged out successfully.\n";
            loggedIn = login();
            if (!loggedIn) {
                std::cout << "Invalid username or password. Exiting...\n";
                return 1;
            }
            break;
        case 7:
            std::cout << "Exiting the program. Thank you!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
