#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = nullptr; }
    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }
    int pop() {
        if (!top) return 0;
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
};

int evaluate(string exp) {
    Stack s;
    for (char ch : exp) {
        if (isdigit(ch)) s.push(ch - '0');
        else {
            int b = s.pop();
            int a = s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string exp = "231*+9-";
    cout << evaluate(exp);
}