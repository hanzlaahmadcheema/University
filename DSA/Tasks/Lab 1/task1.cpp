#include <iostream>
using namespace std;


int sum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++){
    sum += arr[i];
    }
    return sum;
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
    
    cout << "Sum: " << sum(arr, n) << endl;
    return 0;
}