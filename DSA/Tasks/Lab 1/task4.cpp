#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int size) {
    int temp[100], j = 0;
    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int k = 0; k < j; k++) {
            if (arr[i] == temp[k]) {
                found = true;
                break;
            }
        }
        if (!found) temp[j++] = arr[i];
    }
    for (int i = 0; i < j; i++) arr[i] = temp[i];
    return j;
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
    
    int newSize = removeDuplicates(arr, n);
    cout << "Unique elements: "; for (int i = 0; i < newSize; i++) cout << arr[i] << " "; cout << endl;

}