#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if(!top) { cout << "Stack Underflow\n"; return; }
    Node* temp = top;
    cout << "Popped: " << top->data << endl;
    top = top->next;
    delete temp;
}

void display() {
    if(!top) { cout << "Stack is empty\n"; return; }
    Node* temp = top;
    cout << "Stack: ";
    while(temp) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;
}

int main() {
    push(10); push(20); push(30);
    display();
    pop();
    display();
    return 0;
}
