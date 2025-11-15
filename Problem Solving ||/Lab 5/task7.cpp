#include <iostream>
using namespace std;

struct Job {
    string user;
    int priority;
    Job* next;
};

Job* frontPtr = NULL;

void addJob(string u, int p) {
    Job* j = new Job{u, p, NULL};

    if (!frontPtr || frontPtr->priority > p) {
        j->next = frontPtr;
        frontPtr = j;
        return;
    }

    Job* t = frontPtr;
    while (t->next && t->next->priority <= p)
        t = t->next;

    j->next = t->next;
    t->next = j;
}

void processJob() {
    if (!frontPtr) return;
    Job* done = frontPtr;
    frontPtr = frontPtr->next;
    delete done;
}

void cancelJob(string u) {
    if (!frontPtr) return;

    if (frontPtr->user == u) {
        Job* d = frontPtr;
        frontPtr = frontPtr->next;
        delete d;
        return;
    }

    Job* t = frontPtr;
    while (t->next && t->next->user != u)
        t = t->next;

    if (!t->next) return;

    Job* d = t->next;
    t->next = t->next->next;
    delete d;
}

void requeueFailed(string u, int p) {
    addJob(u, p);
}

void display() {
    Job* t = frontPtr;
    while (t) {
        cout << t->user << " P:" << t->priority << endl;
        t = t->next;
    }
}

int main() {
    addJob("Ali", 2);
    addJob("Sara", 1);
    addJob("John", 3);

    cout << "Jobs:" << endl;
    display();

    cancelJob("Ali");

    cout << "After cancel Ali:" << endl;
    display();

    requeueFailed("PrinterErrorJob", 1);

    cout << "After requeue error job:" << endl;
    display();

    processJob();

    cout << "After process 1:" << endl;
    display();
}
