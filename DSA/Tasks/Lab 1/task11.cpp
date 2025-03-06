#include <iostream>
using namespace std;

int arraySum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int findMissingNumber(int arr[], int size) {
    int n = size + 1; 
    int totalSum = (n * (n + 1)) / 2;
    int arrSum = arraySum(arr, size);
    return totalSum - arrSum;
}

int main() {
    int missingArr[] = {1, 2, 4, 5, 6}; 
    cout << "Missing number: " << findMissingNumber(missingArr, 5) << endl;
    return 0;
}
