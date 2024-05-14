#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Creating a queue of integers
    queue<int> myQueue;

    // Enqueue elements
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Dequeue elements
    cout << "Dequeued elements: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;

    // Checking if the queue is empty
    if (myQueue.empty())
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";

    // Enqueue more elements
    myQueue.push(40);
    myQueue.push(50);

    // Checking if the queue is not empty
    if (!myQueue.empty())
        cout << "Queue is not empty\n";
    else
        cout << "Queue is empty\n";

    return 0;
}
