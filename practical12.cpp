#include <iostream>
#include <list>
#include <algorithm>  
using namespace std;

template <typename T>
class PriorityQueue {
private:
    struct Item {
        T data;
        int priority;

        Item(T d, int p) : data(d), priority(p) {}

        bool operator<=(const Item& other) const {
            return priority <= other.priority;
        }
    };

    std::list<Item> queue; 

public:
    void insert(T data, int priority) {
        Item newItem(data, priority);
        
        auto it = queue.begin();
        while (it != queue.end() && it->priority > newItem.priority) {
            ++it;
        }
        queue.insert(it, newItem);
    }

    T remove() {
        if (queue.empty()) {
            cout << "Queue is empty!" << endl;
            return T();  
        }

        T data = queue.front().data;
        queue.pop_front();  
        return data;
    }

    void display() {
        if (queue.empty()) {
            cout << "Queue is empty!" <<endl;
            return;
        }

        cout << "Priority Queue: ";
        for (auto& item : queue) {
            cout << "[" << item.data << " (Priority: " << item.priority << ")] ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue<string> pq;  

    pq.insert("Task 1", 3);
    pq.insert("Task 2", 1);
    pq.insert("Task 3", 2);

    pq.display(); 

    cout << "Removing highest priority item: " << pq.remove() << endl;

    pq.display();  

    return 0;
}
