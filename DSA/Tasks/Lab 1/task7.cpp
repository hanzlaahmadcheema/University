#include <iostream>
using namespace std;

int secondLargest(const int arr[], int size) {
    int first = -1000000, second = -1000000;
    for (int i = 0; i < size; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] < first) {
            second = arr[i];
        }
    }
    return (second == -1000000) ? -1 : second;
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
    cout << "Second largest: " << secondLargest(arr, n) << endl;

}