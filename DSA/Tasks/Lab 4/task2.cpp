#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            count++;
        }
    }

    cout << "The number " << target << " appears " << count << " times." << endl;

    return 0;
}
