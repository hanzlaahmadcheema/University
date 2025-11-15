#include <iostream>
using namespace std;

int main() {
    const int size = 5;
    int arr[size] = {10, 20, 30, 40, 50};
    int element;
    cout << "Element to search: ";
    cin >> element;
    int left = 0;
    int right = size - 1;
    bool found = false;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == element) {
            found = true;
            cout << "Element " << element << " found at " << mid << endl;
            break;
        }
        else if(arr[mid] < element) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    if(!found) {
        cout << "Element " << element << " not found" << endl;
    }
    return 0;
}