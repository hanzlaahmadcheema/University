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
    void pop() {
        if (!top) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    int peek() {
        if (!top) return -1;
        return top->data;
    }
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack s;
    s.push(1); s.push(2); s.pop();
    cout << s.peek();
}