#include <iostream>
using namespace std;

void getEvenNumbers(const int arr[], int size) {
    for (int i = 0; i < size; i++) if (arr[i] % 2 == 0) cout << arr[i] << " ";
    cout << endl;
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
    
    cout << "Even numbers: "; getEvenNumbers(arr, n);
}