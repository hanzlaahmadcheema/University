#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front;
    int rear;

public:
    
    Queue() {
        front = -1;
        rear = -1;
    }

    
    void enqueue(int value) {
        if (rear == 100 - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) front = 0;  
        arr[++rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front++] << endl;
        if (front > rear) {
            
            front = -1;
            rear = -1;
        }
    }

    
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Queue Elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Queue q;
    q.dequeue();
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); 

    return 0;
}
