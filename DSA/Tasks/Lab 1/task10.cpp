#include <iostream>
using namespace std;

int findDuplicate(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) return arr[i];
        }
    }
    return 0;
}

int main() {
    int n;
    cout << "Enter array size:";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter elements in [" << i << "] :";
        cin >> arr[i];
    }
    cout << "Duplicate number: " << findDuplicate(arr, n) << endl;
    return 0;
}
