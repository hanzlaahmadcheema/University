#include <iostream>
using namespace std;

bool isSorted(const int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

int main(){
    int n;
    cout << "Enter array size:";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter elements in [" << i << "] :";
        cin >> arr[i];
    }
    cout << "Is sorted: " << (isSorted(arr, n) ? "Yes" : "No") << endl;
}