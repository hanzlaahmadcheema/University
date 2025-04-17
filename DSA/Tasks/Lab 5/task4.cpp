#include <iostream>
using namespace std;

int binarySearch(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item)
            return mid + 1;
        else if (arr[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void insertionSortArr(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        int pos = binarySearch(arr, key, 0, j);
        cout << "Optimizing: " << key << " to " << pos << endl;

        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArr (int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

int main() {
    int size = 5;
    int arrInsertion[size] = {7, 3, 8, 2, 9};

    cout << "Insertion: Before sorting: ";
    printArr(arrInsertion, size);

    insertionSortArr(arrInsertion, size);
    
    cout << "Insertion: After sorting: ";
    printArr(arrInsertion, size);
    return 0;

}
