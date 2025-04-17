#include <iostream>
using namespace std;

void bubbleSortArr (int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j]< arr[j+ 1])
            {
                swap(arr[j], arr[j+1]);
            }
            
        }
        
    }
    
}

void insertionSortArr (int arr[], int n) {
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
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
    int size = 6;
    int arrBubble[size] = {3, 1, 4, 1, 5, 9};

    cout << "Bubble: Before sorting: ";
    printArr(arrBubble, size);

    bubbleSortArr(arrBubble, size);
    
    cout << "Bubble: After sorting: ";
    printArr(arrBubble, size);

    int arrInsertion[size] = {3, 1, 4, 1, 5, 9};

    cout << "Insertion: Before sorting: ";
    printArr(arrInsertion, size);

    insertionSortArr(arrInsertion, size);
    
    cout << "Insertion: After sorting: ";
    printArr(arrInsertion, size);
    return 0;

}
