#include <iostream>
using namespace std;

void bubbleSortArr (int arr[], int n) {
    int swapCount = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
    }
    cout << "Bubble: Swaps = " << swapCount << endl;
}

void printArr (int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

int main() {
    int size = 4;
    int arrBubble[size] = {5, 3, 2, 1};

    cout << "Bubble: Before sorting: ";
    printArr(arrBubble, size);

    bubbleSortArr(arrBubble, size);
    
    cout << "Bubble: After sorting: ";
    printArr(arrBubble, size);
    return 0;

}
