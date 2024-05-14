#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> myStack; // Creating a stack of integers
    int choice, element;

    do {
        // Menu for user interaction
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Not Empty\n";
        cout << "5. Print Stack Head\n";
        cout << "6. Print Stack Tail\n";
        cout << "7. Print Stack Count\n";
        cout << "8. Print Stack Capacity\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                // Push operation
                cout << "Enter element to push: ";
                cin >> element;
                myStack.push(element);
                cout << "Element " << element << " pushed onto the stack.\n";
                break;
            case 2:
                // Pop operation
                if (!myStack.empty()) {
                    element = myStack.top();
                    myStack.pop();
                    cout << "Element " << element << " popped from the stack.\n";
                } else {
                    cout << "Stack is empty. Cannot pop.\n";
                }
                break;
            case 3:
                // Check if stack is empty
                if (myStack.empty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Stack is not empty.\n";
                }
                break;
            case 4:
                // Check if stack is not empty
                if (!myStack.empty()) {
                    cout << "Stack is not empty.\n";
                } else {
                    cout << "Stack is empty.\n";
                }
                break;
            case 5:
                // Print head of the stack
                if (!myStack.empty()) {
                    cout << "Head of the stack: " << myStack.top() << endl;
                } else {
                    cout << "Stack is empty. No head.\n";
                }
                break;
            case 6:
                // Print tail of the stack
                if (!myStack.empty()) {
                    cout << "Tail of the stack: " << myStack.top() << endl;
                } else {
                    cout << "Stack is empty. No tail.\n";
                }
                break;
            case 7:
                // Print count of elements in the stack
                cout << "Number of elements in the stack: " << myStack.size() << endl;
                break;
            case 8:
                // Print capacity of the stack (not supported in standard stack implementation)
                cout << "Capacity of the stack: Not supported in standard stack implementation.\n";
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
