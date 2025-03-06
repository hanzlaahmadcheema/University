#include <iostream>
using namespace std;

void findCommon(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2 && k < size3) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            cout << arr1[i] << " ";
            i++; j++; k++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr3[k]) {
            j++;
        } else {
            k++;
        }
    }
    cout << endl;
}

int main(){

    int n1;
    cout << "Enter 1st array size:";
    cin >> n1;
    int arr1[n1];

    int n2;
    cout << "Enter 2nd array size:";
    cin >> n2;
    int arr2[n2];

    int n3;
    cout << "Enter 3rd array size:";
    cin >> n3;
    int arr3[n3];

    for (int i = 0; i < n1; i++)
    {
        cout<<"Enter elements in 1st array [" << i << "] :";
        cin >> arr1[i];
    }

    for (int i = 0; i < n2; i++)
    {
        cout<<"Enter elements in 2nd array [" << i << "] :";
        cin >> arr2[i];
    }

    for (int i = 0; i < n3; i++)
    {
        cout<<"Enter elements in 3rd array [" << i << "] :";
        cin >> arr3[i];
    }

    cout << "Common elements: "; findCommon(arr1, n1, arr2, n2, arr3, n3);
}