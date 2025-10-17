#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Enter elements:" << endl;
    for(int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    cout << "Elements in array:" << endl;
    for(int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;   

    return 0;
}