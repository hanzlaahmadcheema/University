#include <iostream>
using namespace std;

int main() {
    int n = 10; // 10, 100, 1000, 10000
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    int com = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            com++;
            cout << ". Comparing arr[" << i << "] and arr[" << j << "] - Comparison: " << com << endl;
        }
    }

    return 0;
}
