#include <iostream>
using namespace std;

void findNumber(int arr[], int n, int target) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) { pos = i; break; }
    }
    if (pos != -1) cout << "Index: " << pos << endl;
    else cout << "Not Found." << endl;
}


int main() {

    int arr[5] = {1, 4, 6, 8, 10};
    findNumber(arr, 5, 8);

    return 0;
}
