/*
Implementing linear search recursively in C++ is straightforward: you search an element by comparing it with 
each element in the array, one by one, until you find it or reach the end. Here’s how a recursive linear search
 works along with its time complexity.

Recursive Linear Search
In a recursive linear search:

Base Case: If the current element is the target, return its index. If the end of the array is reached without 
finding the target, return -1 (indicating the target isn’t in the array).
Recursive Case: Move to the next element by calling the function with the next index.
*/
#include <iostream>
using namespace std;
#include <vector>

int recursiveLinearSearch(const vector<int>& arr, int target, int index) {
    // Base case: If index is beyond the last element, target is not in array
    if (index >= arr.size()) {
        return -1;  // Target not found
    }

    // If the current element is the target, return its index
    if (arr[index] == target) {
        return index;
    }

    // Recursive case: Check the next element
    return recursiveLinearSearch(arr, target, index + 1);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target = 7;

    int result = recursiveLinearSearch(arr, target, 0);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}

/*
Function Call: recursiveLinearSearch(arr, target, 0) starts the search from the beginning of the array.
Base Case: If the index reaches the size of arr, it means the element wasn’t found, so it returns -1.
Recursive Step: Each recursive call checks the next element by incrementing index by 1.
Time Complexity of Recursive Linear Search
For a linear search (iterative or recursive), the time complexity is:

Best Case: 

O(1), if the target is the first element.
Worst Case: 

O(n), if the target is the last element or not in the array.
Average Case: 

O(n), as on average, the function will check about half the elements for random target positions.
*/
