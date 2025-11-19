#include <iostream>
using namespace std;

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
bool isEmpty() { return top == -1; }

int precedence(char c) {
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    string postfix = "";
    for(char c: infix) {
        if(isalpha(c) || isdigit(c)) postfix += c;
        else if(c=='(') push(c);
        else if(c==')') {
            while(!isEmpty() && peek()!='(') postfix += pop();
            pop(); // remove '('
        } else {
            while(!isEmpty() && precedence(peek())>=precedence(c)) postfix += pop();
            push(c);
        }
    }
    while(!isEmpty()) postfix += pop();
    return postfix;
}

int main() {
    string expr = "(4*2)+6/5*4";
    cout << "Postfix: " << infixToPostfix(expr) << endl;
    return 0;
}
