#include <iostream>
using namespace std;

int main() {
    int n = 100; // 10, 100, 1000, 10000 
    int target = n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    int s=0;
    int com=0;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        com++;
        s++;
        cout<<s<<". Mid: " << mid;
        cout<< " - Comparison: " << com<<endl;
        if (arr[mid] == target) {
            return 0;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;

    
    
}