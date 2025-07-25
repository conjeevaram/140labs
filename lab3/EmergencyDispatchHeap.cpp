#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Call {
    int id;
    int severity;
    int waitTime;
    string location;

    Call() : id(0), severity(0), waitTime(0), location("") {}
    Call(int id, int severity, int waitTime, string location)
        : id(id), severity(severity), waitTime(waitTime), location(location) {}

    int getPriority() const {
        return severity * 10 - waitTime * waitTime;
    }

    void print() const {
        cout << "Call ID: " << id
             << ", Severity: " << severity
             << ", Wait Time: " << waitTime
             << ", Location: " << location
             << ", Priority: " << getPriority()
             << endl;
    }
};

class MinHeap {
private:
    vector<Call> elements;
    int size;
    unordered_map<int, int> idToIndex;

public:
    MinHeap();
    bool Enqueue(Call call);
    Call Dequeue();
    void ReheapUp(int index);
    void ReheapDown(int index);
    void updateWaitTimes();
    void printAll();
    int getSize();
    bool updateCall(int callID, int newSeverity);
};

MinHeap::MinHeap() {
    elements.push_back(Call()); // dummy node at index 0
    size = 0;
}

bool MinHeap::Enqueue(Call call) {
    // TODO: Insert call, update idToIndex, call ReheapUp
    return false;
}

Call MinHeap::Dequeue() {
    // TODO: Remove and return root call (min priority), call ReheapDown
    return Call(-999, 0, 0, "EMPTY");
}

void MinHeap::ReheapUp(int index) {
    // TODO: Maintain heap by swapping upward
}

void MinHeap::ReheapDown(int index) {
    // TODO: Maintain heap by swapping downward
}

void MinHeap::updateWaitTimes() {
    // TODO: Increment waitTime for all calls, update priorities
}

void MinHeap::printAll() {
    if (size == 0) {
        cout << "No active calls in the queue.\n";
        return;
    }
    for (int i = 1; i <= size; i++) {
        elements[i].print();
    }
}

int MinHeap::getSize() {
    return size;
}

bool MinHeap::updateCall(int callID, int newSeverity) {
    // TODO: Update severity of a specific call and reheap
    return false;
}

int main() {
    MinHeap dispatch;
    int choice, callID = 1;

    while (true) {
        cout << "\n--- Emergency Dispatch System ---\n";
        cout << "1. Add Emergency Call\n";
        cout << "2. Update Wait Times + Dispatch\n";
        cout << "3. Change Severity of Call by ID\n";
        cout << "4. Print Call Queue\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            int severity;
            string location;
            cout << "Enter severity (1-10): ";
            cin >> severity;
            cin.ignore();
            cout << "Enter location: ";
            getline(cin, location);
            Call newCall(callID++, severity, 0, location);
            if (!dispatch.Enqueue(newCall))
                cout << "Heap full or enqueue failed!\n";
            else
                cout << "Call added successfully.\n";
        } else if (choice == 2) {
            dispatch.updateWaitTimes();
            if (dispatch.getSize() > 0) {
                Call next = dispatch.Dequeue();
                cout << "\n--- Dispatching Call ---\n";
                next.print();
            } else {
                cout << "No calls to dispatch.\n";
            }
        } else if (choice == 3) {
            int id, newSeverity;
            cout << "Enter Call ID to update: ";
            cin >> id;
            cout << "Enter new severity (1-10): ";
            cin >> newSeverity;
            if (!dispatch.updateCall(id, newSeverity))
                cout << "Call not found.\n";
            else
                cout << "Severity updated.\n";
        } else if (choice == 4) {
            cout << "\n--- Current Call Queue ---\n";
            dispatch.printAll();
        } else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
