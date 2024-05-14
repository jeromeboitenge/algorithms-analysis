/*Initialize two variables candidate and count to None and 0 respectively.
Iterate through the array:
If count is 0, set the current element as the candidate and set count to 1.
If the current element is equal to the candidate, increment count by 1.
If the current element is different from the candidate, decrement count by 1.
After the iteration, candidate will hold the potential majority element.
Verify if the candidate is indeed the majority element by counting its 
occurrences in the array. If it appears more than n/2 times, it is 
the majority element; otherwise, there's no majority element.*/
#include <iostream>
#include <vector>
using namespace std;

int findMajorityElement(vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    // Finding a candidate for majority element
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Verifying if the candidate is the majority element
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > nums.size() / 2) {
        return candidate;
    } else {
        return -1; // No majority element found
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int majorityElement = findMajorityElement(nums);
    if (majorityElement != -1) {
        cout << "Majority element: " << majorityElement << endl;
    } else {
        cout << "No majority element found" << endl;
    }
    return 0;
}
