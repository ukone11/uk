#include <iostream>
using namespace std;

struct Seat {
    int seatNumber;
    bool isBooked;
    Seat* next;
    Seat* prev;
};

Seat* createRow(int rowNumber, int seats) {
    Seat* head = nullptr;
    Seat* tail = nullptr;

    for (int i = 1; i <= seats; i++) {
        Seat* newSeat = new Seat;
        newSeat->seatNumber = i;
        newSeat->isBooked = false;
        newSeat->next = newSeat->prev = nullptr;

        if (!head) {
            head = newSeat;
            tail = newSeat;
            newSeat->next = newSeat;
            newSeat->prev = newSeat;
        } else {
            tail->next = newSeat;
            newSeat->prev = tail;
            newSeat->next = head;
            head->prev = newSeat;
            tail = newSeat;
        }
    }

    return head;
}

void displayAvailableSeats(Seat* head) {
    if (!head) return;

    Seat* temp = head;
    cout << "Available seats: ";
    do {
        if (!temp->isBooked)
            cout << temp->seatNumber << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

bool bookSeat(Seat* head, int seatNumber) {
    if (!head) return false;

    Seat* temp = head;
    do {
        if (temp->seatNumber == seatNumber) {
            if (temp->isBooked) {
                cout << "Seat " << seatNumber << " is already booked!\n";
                return false;
            }
            temp->isBooked = true;
            cout << "Seat " << seatNumber << " booked successfully!\n";
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Seat " << seatNumber << " does not exist in this row.\n";
    return false;
}

bool cancelBooking(Seat* head, int seatNumber) {
    if (!head) return false;

    Seat* temp = head;
    do {
        if (temp->seatNumber == seatNumber) {
            if (!temp->isBooked) {
                cout << "Seat " << seatNumber << " is not booked yet!\n";
                return false;
            }
            temp->isBooked = false;
            cout << "Seat " << seatNumber << " booking cancelled successfully!\n";
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Seat " << seatNumber << " does not exist in this row.\n";
    return false;
}

int main() {
    const int rows = 10;
    const int seatsPerRow = 7;
    Seat* theater[rows];

    for (int i = 0; i < rows; i++) {
        theater[i] = createRow(i + 1, seatsPerRow);
    }

    int choice, rowNumber, seatNumber;

    do {
        cout << "\nCinemax Theater Booking System\n";
        cout << "1. Display available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Cancel a booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter row number (1-10): ";
                cin >> rowNumber;
                if (rowNumber >= 1 && rowNumber <= rows) {
                    displayAvailableSeats(theater[rowNumber - 1]);
                } else {
                    cout << "Invalid row number!\n";
                }
                break;

            case 2:
                cout << "Enter row number (1-10): ";
                cin >> rowNumber;
                cout << "Enter seat number (1-7): ";
                cin >> seatNumber;
                if (rowNumber >= 1 && rowNumber <= rows) {
                    bookSeat(theater[rowNumber - 1], seatNumber);
                } else {
                    cout << "Invalid row number!\n";
                }
                break;

            case 3:
                cout << "Enter row number (1-10): ";
                cin >> rowNumber;
                cout << "Enter seat number (1-7): ";
                cin >> seatNumber;
                if (rowNumber >= 1 && rowNumber <= rows) {
                    cancelBooking(theater[rowNumber - 1], seatNumber);
                } else {
                    cout << "Invalid row number!\n";
                }
                break;

            case 4:
                cout << "Exiting the system. Thank you!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
