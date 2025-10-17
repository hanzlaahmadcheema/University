#include <iostream>
using namespace std;

int main() {
    const int size = 5;
    int arr[size] = {10, 20, 30, 40, 50};
    int element;
    cout << "Element to search: ";
    cin >> element;
    bool found = false;
    for(int i = 0; i < size; ++i) {
        if(arr[i] == element) {
            found = true;
            cout << "Element " << element << " found at " << i << endl;
            break;
        }
    }
    if(!found) {
        cout << "Element " << element << " not found" << endl;
    }

    return 0;
}