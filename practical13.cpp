#include <iostream>
#include <string>

using namespace std;

class PizzaParlor {
private:
    string* queue;   // Array to store orders
    int front;       // Front of the queue
    int rear;        // Rear of the queue
    int capacity;    // Maximum number of orders (M)
    int size;        // Current number of orders in the queue

public:
    // Constructor to initialize the pizza parlor with capacity M
    PizzaParlor(int M) {
        capacity = M;
        queue = new string[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor to clean up the allocated memory
    ~PizzaParlor() {
        delete[] queue;
    }

    // Function to place a new order in the queue
    void placeOrder(string order) {
        if (size == capacity) {
            cout << "Sorry, the pizza parlor is full. Cannot accept more orders." << endl;
            return;
        }
        if (front == -1) {
            front = 0;  // First order
        }
        rear = (rear + 1) % capacity;  // Circular increment
        queue[rear] = order;
        size++;
        cout << "Order placed: " << order << endl;
    }

    // Function to serve an order (remove from the queue)
    void serveOrder() {
        if (size == 0) {
            cout << "No orders to serve." << endl;
            return;
        }
        cout << "Serving order: " << queue[front] << endl;
        front = (front + 1) % capacity;  // Circular increment
        size--;
    }

    // Function to display all current orders in the queue
    void displayOrders() {
        if (size == 0) {
            cout << "No orders in the queue." << endl;
            return;
        }

        cout << "Current orders in the queue: ";
        int i = front;
        for (int j = 0; j < size; j++) {
            cout << queue[i] << " ";
            i = (i + 1) % capacity;  // Circular increment
        }
        cout << endl;
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    int M;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> M;

    PizzaParlor parlor(M);

    int choice;
    string order;

    do {
        cout << "\n--- Pizza Parlor ---\n";
        cout << "1. Place an order\n";
        cout << "2. Serve an order\n";
        cout << "3. Display all orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (parlor.isFull()) {
                    cout << "The pizza parlor is full! Cannot place any more orders." << endl;
                } else {
                    cout << "Enter order description: ";
                    cin.ignore();  // To ignore the newline character left by cin
                    getline(cin, order);
                    parlor.placeOrder(order);
                }
                break;

            case 2:
                parlor.serveOrder();
                break;

            case 3:
                parlor.displayOrders();
                break;

            case 4:
                cout << "Exiting the pizza parlor system.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
