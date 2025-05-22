#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = nullptr; }
    void push(char x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }
    char pop() {
        if (!top) return '\0';
        Node* temp = top;
        char val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }
};

int main() {
    string input = "hello";
    Stack s;
    for (char c : input) s.push(c);
    while (true) {
        char c = s.pop();
        if (c == '\0') break;
        cout << c;
    }
}