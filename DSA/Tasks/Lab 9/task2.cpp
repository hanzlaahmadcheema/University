#include <iostream>
using namespace std;


class Stack {
private:
    int top;
    int arr[100]; 
public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        return arr[top];
    }
};


class Queue {
private:
    int front, rear;
    int arr[100]; 
public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == 99;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = val;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getFront() {
        if (!isEmpty()) return arr[front];
        return -1;
    }

    int size() {
        return isEmpty() ? 0 : rear - front + 1;
    }
};


void reverseQueue(Queue &q) {
    Stack s;

    
    while (!q.isEmpty()) {
        s.push(q.dequeue());
    }

    
    while (!s.isEmpty()) {
        q.enqueue(s.pop());
    }
}


int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Original Queue: ";
    q.display();

    reverseQueue(q);

    cout << "Reversed Queue: ";
    q.display();

    return 0;
}
