#include <iostream>
using namespace std;

int main() {
    const int size = 5;
    int arr[size] = {1, 2, 3, 4, 5};
    int sum = 0;

    for(int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    cout << "Sum: " << sum << endl; 
    return 0;
}