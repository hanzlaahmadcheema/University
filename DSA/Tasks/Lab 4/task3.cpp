#include <iostream>
#include <unordered_set>
using namespace std;

//Using hash
int main() {
    int arr[] = {3, 1, 4, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    unordered_set<int> seen;  
    bool found = false;

    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];

        if (seen.find(complement) != seen.end()) {
            cout << "Pair found: " << arr[i] << " + " << complement << " = " << target << endl;
            found = true;
            break;
        }

        seen.insert(arr[i]);  
    }

    if (!found) {
        cout << "No pair found with the given sum." << endl;
    }

    return 0;
}
