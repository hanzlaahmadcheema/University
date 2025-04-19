/*

Recursion in C++ refers to a function calling itself to solve a problem. Each recursive call simplifies the problem, and recursion continues until a base case is reached, where the solution is simple enough to return a result without further recursion.

Basic Structure of a Recursive Function
A recursive function typically has:

Base Case: A condition under which the function stops calling itself.
Recursive Case: The part where the function calls itself with a modified argument to approach the base case.
Base Case: 

0!=1
Recursive Case: 
𝑛!=𝑛×(𝑛−1)!

*/
#include <iostream>
using namespace std;
int factorial(int n) {
    // Base case
    if (n <= 1) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}

int main() {
    int number = 5;
    cout << "Factorial of " << number << " is " << factorial(number) << endl;
    return 0;
}
