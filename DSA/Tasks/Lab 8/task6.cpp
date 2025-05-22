#include <iostream>
using namespace std;

struct Node {
    int data;
    int min;
    Node* next;
};

class MinStack {
    Node* top;
public:
    MinStack() { top = nullptr; }
    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->min = (top ? std::min(x, top->min) : x);
        temp->next = top;
        top = temp;
    }
    void pop() {
        if (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    int getMin() {
        return top ? top->min : -1;
    }
};

int main() {
    MinStack s;
    s.push(3); s.push(5); s.push(2);
    cout << s.getMin();
}