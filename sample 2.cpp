#include <iostream>
#include <string>
#include <list>

using namespace std;


const int MAX_CAPACITY = 57;


list<string> licensePlates;
list<string> ownerNames;
list<string> carModels;


void initializeParkingLot() {
    for (int i = 0; i < 52; ++i) {
        licensePlates.push_back("Car_" + to_string(i + 1));
        ownerNames.push_back("Owner_" + to_string(i + 1));
        carModels.push_back("Model_" + to_string(i + 1));
    }
    for (int i = 52; i < MAX_CAPACITY; ++i) {
        licensePlates.push_back("");
        ownerNames.push_back("");
        carModels.push_back("");
    }
    cout << "Initialized parking lot with 52 cars and 5 extra empty slots for future use.\n";
}


void displayParkingSlots() {
    cout << "\n--- Welcome to Alhemd Parking ---\n";
    int slotNumber = 1;
    auto itPlate = licensePlates.begin();
    for (; itPlate != licensePlates.end(); ++itPlate, ++slotNumber) {
        cout << "Slot " << slotNumber << ": " << " BMW ";
        if (itPlate->empty()) {
            cout << "[Empty]\n";
        } else {
            cout << *itPlate << "\n";
        }
    }
}

void displaySlotDetails(int slotNumber) {
    if (slotNumber < 1 || slotNumber > MAX_CAPACITY) {
        cout << "Invalid slot number.\n";
        return;
    }

    auto itPlate = licensePlates.begin();
    auto itOwner = ownerNames.begin();
    auto itModel = carModels.begin();

    advance(itPlate, slotNumber - 1);
    advance(itOwner, slotNumber - 1);
    advance(itModel, slotNumber - 1);

    if (itPlate->empty()) {
        cout << "Slot " << slotNumber << " is empty.\n";
    } else {
        cout << "Slot  " << slotNumber << ":\n";
        cout << "- BXE 678 : " << *itPlate << "\n";
        cout << "- Ali : " << *itOwner << "\n";
        cout << "- BMW Series 2:  " << *itModel << "\n";
        cout << endl;
    }
    
}

int main() {
    initializeParkingLot();

    int choice;
    do {
        cout << "\n--- ALHEMD PARKING ---\n";
        cout << "1. View Parking Slots\n";
        cout << "2. View Slot Details\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayParkingSlots();
                break;
            case 2: {
                int slotNumber;
                cout << "Enter the slot number to view details: ";
                cin >> slotNumber;
                displaySlotDetails(slotNumber);
                break;
            }
            case 3:
                cout << " Thank you for using our parking \n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
