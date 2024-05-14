#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Creating a queue of integers
    queue<int> myQueue;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check if queue is empty\n";
        cout << "4. Display head, tail, count, and capacity\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                myQueue.push(value);
                cout << value << " enqueued.\n";
                break;
            case 2:
                if (!myQueue.empty()) {
                    cout << myQueue.front() << " dequeued.\n";
                    myQueue.pop();
                } else {
                    cout << "Queue is empty. Cannot dequeue.\n";
                }
                break;
            case 3:
                if (myQueue.empty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;
            case 4:
                cout << "Head: " << (myQueue.empty() ? "N/A" : to_string(myQueue.front())) << endl;
                cout << "Tail: " << (myQueue.empty() ? "N/A" : to_string(myQueue.back())) << endl;
                cout << "Count: " << myQueue.size() << endl;
                cout << "Capacity: Unlimited (dynamic allocation)\n";
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while(choice != 5);

    return 0;
}
