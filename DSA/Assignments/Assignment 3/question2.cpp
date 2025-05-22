#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    queue<int> firstHalf;

    // Step 1: Push first half into firstHalf queue
    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: Interleave firstHalf and remaining queue
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int x : arr) q.push(x);

    interleaveQueue(q);

    while (!q.empty()) {
        cout << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
    }
}
