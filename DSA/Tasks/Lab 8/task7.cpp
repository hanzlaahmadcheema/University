#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& top, int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop(Node*& top) {
    if (!top) return -1;
    int val = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return val;
}

Node* reverseList(Node* head) {
    Node* stack = nullptr;
    Node* temp = head;
    while (temp) {
        push(stack, temp->data);
        temp = temp->next;
    }

    Node* newHead = nullptr;
    while (stack) {
        push(newHead, pop(stack));
    }
    return newHead;
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, new Node{4, nullptr}}}};
    Node* reversed = reverseList(head);
    print(reversed);
}