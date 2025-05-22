#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = nullptr; }
    void push(char c) {
        Node* temp = new Node();
        temp->data = c;
        temp->next = top;
        top = temp;
    }
    char pop() {
        if (!top) return '\0';
        char val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    bool isEmpty() { return top == nullptr; }
    char peek() { return top ? top->data : '\0'; }
};

bool match(char o, char c) {
    return (o == '(' && c == ')') || (o == '{' && c == '}') || (o == '[' && c == ']');
}

bool isBalanced(string s) {
    Stack stack;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') stack.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty() || !match(stack.pop(), ch)) return false;
        }
    }
    return stack.isEmpty();
}

int main() {
    cout << (isBalanced("({[()]})") ? "Balanced" : "Not Balanced") << endl;
    cout << (isBalanced("({[([)])}") ? "Balanced" : "Not Balanced") << endl;
}