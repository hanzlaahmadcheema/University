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
        Node* n = new Node();
        n->data = x;
        n->next = top;
        top = n;
    }
    int pop() {
        if (!top) return -1;
        int val = top->data;
        Node* t = top;
        top = top->next;
        delete t;
        return val;
    }
    int peek() { return top ? top->data : -1; }
    bool isEmpty() { return top == nullptr; }
};

void nextGreater(int arr[], int n) {
    Stack s;
    int* res = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        while (!s.isEmpty() && s.peek() <= arr[i]) s.pop();
        res[i] = s.isEmpty() ? -1 : s.peek();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++) cout << res[i] << " ";
    delete[] res;
}

int main() {
    int arr[] = {4, 5, 2, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextGreater(arr, n);
}