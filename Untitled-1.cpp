

// Structure to represent a room
struct Room {
    int roomId;
    bool isReserved;
};

// Function to display menu and get user choice
int displayMenu() {
    std::cout << "========== Moon Hotel Menu ==========\n";
    std::cout << "1. View Rooms\n";
    std::cout << "2. Book Room\n";
    std::cout << "3. View Bookings\n";
    std::cout << "4. Prepare Bill\n";
    std::cout << "5. Exit\n";
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
void bookRoom(Room rooms[], int numRooms) {
    int roomId;
    std::cout << "Enter the Room ID to book: ";
    std::cin >> roomId;

    // Assume basic validation, and the room ID exists
    rooms[roomId - 1].isReserved = true;

    std::cout << "Room booked successfully!\n";
}

// Function to view booked rooms
void viewBookings(const Room rooms[], int numRooms) {
    std::cout << "Booked Rooms:\n";
    for (int i = 0; i < numRooms; ++i) {
        if (rooms[i].isReserved) {
            std::cout << "Room ID: " << rooms[i].roomId << "\n";
        }
    }
}

// Function to prepare a bill
void prepareBill() {
    // Assume a simple bill preparation process
    double totalAmount = 100.0;  // Sample amount
    std::cout << "Total Bill Amount: $" << std::fixed << std::setprecision(2) << totalAmount << "\n";
}

int main() {
    const int numRooms = 5;  // Number of rooms in Moon Hotel
    Room rooms[numRooms] = {{1, false}, {2, false}, {3, false}, {4, false}, {5, false}};

    int choice;
    do {
        choice = displayMenu();

        switch (choice) {
            case 1:
                viewRooms(rooms, numRooms);
                break;
            case 2:
                bookRoom(rooms, numRooms);
                break;
            case 3:
                viewBookings(rooms, numRooms);
                break;
            case 4:
                prepareBill();
                break;
            case 5:
                std::cout << "Exiting the program. Thank you!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}