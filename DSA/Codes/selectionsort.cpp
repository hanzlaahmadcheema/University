#include <iostream>
using namespace std;

// Function to implement Selection Sort in-place
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // Assume the minimum is the first element
        int minIndex = i;

        // Check the rest of the array for a smaller element
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Selection Sort
    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
/*
The algorithm maintains two parts in the array: a sorted part and an unsorted part.
For each position 

i in the array:
It assumes the current position is the minimum.
It searches the rest of the array to find the true minimum.
Once the minimum is found, it swaps it with the element at position 

i, placing it in its correct position in the sorted part.
This process continues until the entire array is sorted.
printArray function:

A utility function to print the contents of the array.*/