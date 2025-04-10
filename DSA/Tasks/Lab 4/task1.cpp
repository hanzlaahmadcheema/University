#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 2, 6, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);  
    int target = 2;

    int first = -1;
    int last = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            if (first == -1) {
                first = i;  
            }
            last = i;  
        }
    }

    if (first != -1) {
        cout << "First occurrence = " << first << endl;
        cout << "Last occurrence = " << last << endl;
    } else {
        cout << "Target not found!" << endl;
    }

    return 0;
}