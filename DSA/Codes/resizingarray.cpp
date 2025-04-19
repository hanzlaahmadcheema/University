/*If you want to resize an array in C++ without using vector, you need to use dynamic memory allocation with new and delete. Here’s how you can do it:

Allocate a new array of the desired size.
Copy the elements from the old array to the new array.
Delete the old array to free up memory.
Update the pointer to the new array.*/
#include <iostream>
using namespace std;
#include <algorithm>  // for copy

int* resizeArray(int* arr, int oldSize, int newSize) {
    // Step 1: Allocate a new array of the new size
    int* newArr = new int[newSize];

    // Step 2: Copy elements from the old array to the new array
    int elementsToCopy = min(oldSize, newSize);  // Avoid out-of-bounds issues
    copy(arr, arr + elementsToCopy, newArr);

    // Step 3: Delete the old array
    delete[] arr;

    // Step 4: Return the new array pointer
    return newArr;
}

int main() {
    int oldSize = 5;
    int* arr = new int[oldSize] {1, 2, 3, 4, 5};  // Initial array with 5 elements

    // Display the initial array
    cout << "Old array: ";
    for (int i = 0; i < oldSize; ++i) {
        cout << arr[i] << " ";
    }
   cout << endl;

    // Resizing the array to a new size
    int newSize = 8;
    arr = resizeArray(arr, oldSize, newSize);

    // Display the resized array
    cout << "Resized array: ";
    for (int i = 0; i < newSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Free the resized array memory
    delete[] arr;

    return 0;
}
