#include <iostream>
#include <queue>
#include <string>

using namespace std;

class JobQueue {
private:
    queue<string> jobQueue;  

public:
    void addJob(const string& jobName) {
        jobQueue.push(jobName);
        cout << "Job '" << jobName << "' added to the queue." << endl;
    }

    void deleteJob() {
        if (jobQueue.empty()) {
            cout << "No jobs in the queue to delete!" << endl;
        } else {
            string jobName = jobQueue.front();
            jobQueue.pop();
            cout << "Job '" << jobName << "' processed and removed from the queue." << endl;
        }
    }

    void displayQueue() {
        if (jobQueue.empty()) {
            cout << "No jobs in the queue." << endl;
        } else {
            cout << "Current jobs in the queue: ";
            queue<string> tempQueue = jobQueue;  
            while (!tempQueue.empty()) {
                cout << tempQueue.front() << " ";
                tempQueue.pop();
            }
            cout << endl;
        }
    }
};

int main() {
    JobQueue jq;
    int choice;
    string jobName;

    do {
        cout << "\n--- Job Queue Simulator ---\n";
        cout << "1. Add job to queue\n";
        cout << "2. Delete job from queue (process job)\n";
        cout << "3. Display current jobs in the queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job name: ";
                cin >> jobName;
                jq.addJob(jobName);
                break;
            case 2:
                jq.deleteJob();
                break;
            case 3:
                jq.displayQueue();
                break;
            case 4:
                cout << "Exiting the Job Queue Simulator.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
