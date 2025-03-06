#include <iostream>
using namespace std;

int count(const int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) if (arr[i] == target) count++;
    return count;
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
    
    int target;
    cout << "Enter target number: ";
    cin >> target;
    cout << "Number of occurrences of " << target << " in the array: " << count(arr, n, target) << endl;
    return 0;

}