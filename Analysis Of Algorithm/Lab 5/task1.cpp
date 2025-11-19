#include <iostream>
using namespace std;
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int* dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int result = dp[n];
    delete[] dp;
    return result;
}
int main() {
    int n;
    cout << "Enter an integer n to find the nᵗʰ Fibonacci number: ";
    cin >> n;
    int result = fibonacci(n);
    cout << "The " << n << "ᵗʰ Fibonacci number is: " << result << endl;
    return 0;
}