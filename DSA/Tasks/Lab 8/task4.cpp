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
        if (!top) return -1;
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    int peek() { return top ? top->data : -1; }
    bool isEmpty() { return top == nullptr; }
};

void sortedInsert(Stack &s, int x) {
    if (s.isEmpty() || x > s.peek()) {
        s.push(x);
        return;
    }
    int temp = s.pop();
    sortedInsert(s, x);
    s.push(temp);
}

void sortStack(Stack &s) {
    if (!s.isEmpty()) {
        int x = s.pop();
        sortStack(s);
        sortedInsert(s, x);
    }
}

void printStack(Stack s) {
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
}

int main() {
    Stack s;
    s.push(3); s.push(1); s.push(4); s.push(2);
    sortStack(s);
    printStack(s);
}