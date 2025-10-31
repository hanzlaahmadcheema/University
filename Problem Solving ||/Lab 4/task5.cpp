#include <iostream>
using namespace std;
#define MAX 100
class PrintJob {
public:
    int jobId;
    int priority;
    PrintJob(int id, int prio) : jobId(id), priority(prio) {}
};
class PrintQueue {
private:
    PrintJob* arr[MAX];
    int front;
    int rear;
public:
    PrintQueue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1 || front > rear;
    }
    bool isFull() {
        return rear == MAX - 1;
    }
    void enqueue(int jobId, int priority) {
        if (isFull()) {
            cout << "Print queue is full. Cannot enqueue job " << jobId << endl;
            return;
        }
        PrintJob* newJob = new PrintJob(jobId, priority);
        if (isEmpty()) {
            front = 0;
        }
        arr[++rear] = newJob;
        cout << "Job " << jobId << " with priority " << priority << " enqueued to print queue." << endl;
    }
    PrintJob* dequeue() {
        if (isEmpty()) {
            cout << "Print queue is empty. Cannot dequeue." << endl;
            return nullptr;
        }
        
        int highestPriorityIndex = front;
        for (int i = front + 1; i <= rear; i++) {
            if (arr[i]->priority < arr[highestPriorityIndex]->priority) {
                highestPriorityIndex = i;
            }
        }
        PrintJob* jobToProcess = arr[highestPriorityIndex];
        
        for (int i = highestPriorityIndex; i < rear; i++) {
            arr[i] = arr[i + 1];
        }
        rear--;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        cout << "Job " << jobToProcess->jobId << " with priority " << jobToProcess->priority << " dequeued from print queue." << endl;
        return jobToProcess;
    }
    void display() {
        if (isEmpty()) {
            cout << "Print queue is empty." << endl;
            return;
        }
        cout << "Print Queue elements (JobID:Priority): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i]->jobId << ":" << arr[i]->priority << " ";
        }
        cout << endl;
    }
};
int main() {
    PrintQueue pq;
    pq.enqueue(101, 2);
    pq.enqueue(102, 1);
    pq.enqueue(103, 3);
    pq.display();
    PrintJob* job = pq.dequeue();
    delete job;
    pq.display();
    pq.enqueue(104, 1);
    pq.display();
    while (!pq.isEmpty()) {
        PrintJob* job = pq.dequeue();
        delete job;
    }
    pq.display();
    return 0;
}