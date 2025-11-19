#include <iostream>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if(top == MAX-1) { cout << "Stack Overflow\n"; return; }
    stack[++top] = val;
}

void pop() {
    if(top == -1) { cout << "Stack Underflow\n"; return; }
    cout << "Popped: " << stack[top--] << endl;
}

void display() {
    if(top == -1) { cout << "Stack is empty\n"; return; }
    cout << "Stack: ";
    for(int i=0; i<=top; i++) cout << stack[i] << " ";
    cout << endl;
}

int main() {
    push(10); push(20); push(30);
    display();
    pop();
    display();
    return 0;
}
