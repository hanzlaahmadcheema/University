#include <iostream>
using namespace std;

int main() {
    const int size = 5;
    int arr[size] = {64, 25, 12, 22, 11};
    for(int i = 0; i < size - 1; ++i) {
        int min = i;
        for(int j = i + 1; j < size; ++j) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    cout << "Sorted array: ";
    for(int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}