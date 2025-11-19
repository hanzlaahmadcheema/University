#include <iostream>
using namespace std;

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
bool isEmpty() { return top == -1; }

bool isBalanced(string expr) {
    for(char c: expr) {
        if(c=='(') push(c);
        else if(c==')') {
            if(isEmpty()) return false;
            pop();
        }
    }
    return isEmpty();
}

int main() {
    string expr = "(a+b)*(c+d)";
    if(isBalanced(expr)) cout << "Balanced\n";
    else cout << "Not Balanced\n";
    return 0;
}
