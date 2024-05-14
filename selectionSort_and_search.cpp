#include <iostream>
#include <vector>

using namespace std;

// Recursive linear search function
int recursiveLinearSearch(vector<int>& arr, int value, int index) {
    if (index >= arr.size()) {
        return -1; // Element not found
    }
    if (arr[index] == value) {
        return index; // Element found at index
    }
    return recursiveLinearSearch(arr, value, index + 1); // Recursive call
}

// Selection sort function
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int valueToSearch;
    cout << "Enter the value to search: ";
    cin >> valueToSearch;

    // Perform selection sort
    selectionSort(arr);

    // Print sorted array
    cout << "Sorted array:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Perform recursive linear search
    int index = recursiveLinearSearch(arr, valueToSearch, 0);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
