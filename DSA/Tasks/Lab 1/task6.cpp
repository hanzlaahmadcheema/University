#include <iostream>
using namespace std;

void rotateLeft(int arr[], int size, int positions) {
    positions %= size;
    int temp[100];
    for (int i = 0; i < positions; i++) temp[i] = arr[i];
    for (int i = 0; i < size - positions; i++) arr[i] = arr[i + positions];
    for (int i = 0; i < positions; i++) arr[size - positions + i] = temp[i];
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

    rotateLeft(arr, n, 2);
    cout << "Rotated left: "; for (int i = 0; i < n; i++) cout << arr[i] << " "; cout << endl;
}