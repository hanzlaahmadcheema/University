#include <iostream>
#include <queue>
#include <string>
using namespace std;

void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1");

    for (int i = 0; i < n; i++) {
        string curr = q.front();
        q.pop();
        cout << curr << (i == n - 1 ? "\n" : ", ");

        q.push(curr + "0");
        q.push(curr + "1");
    }
}

int main() {
    int n = 5;
    generateBinaryNumbers(n);
}
