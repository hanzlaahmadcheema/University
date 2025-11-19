#include <iostream>
using namespace std;

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

int main() {
    string str = "HelloWorld";
    for(char c: str) push(c);
    for(int i=0; i<str.length(); i++) str[i] = pop();
    cout << "Reversed: " << str << endl;
    return 0;
}
