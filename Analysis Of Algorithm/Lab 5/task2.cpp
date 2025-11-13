#include <iostream>
using namespace std;
int climbStairs(int n) {
    if (n <= 1) return 1;

    int* dp = new int[n + 1];
    dp[0] = 1; 
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
    cout << "Enter the number of steps in the staircase: ";
    cin >> n;
    int ways = climbStairs(n);
    cout << "Number of distinct ways to reach the top: " << ways << endl;
    return 0;
}