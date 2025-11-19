#include <iostream>
using namespace std;

struct Patient {
    string name;
    int priority;
    Patient* next;
};

Patient* frontPtr = NULL;

void enqueue(string n, int p) {
    Patient* temp = new Patient{n, p, NULL};

    if (!frontPtr || frontPtr->priority > p) {
        temp->next = frontPtr;
        frontPtr = temp;
        return;
    }

    Patient* t = frontPtr;
    while (t->next && t->next->priority <= p)
        t = t->next;

    temp->next = t->next;
    t->next = temp;
}

void treat() {
    if (!frontPtr) return;
    Patient* d = frontPtr;
    frontPtr = frontPtr->next;
    delete d;
}

void upgrade(string n, int newP) {
    if (!frontPtr) return;

    Patient* t = frontPtr;
    Patient* prev = NULL;

    while (t && t->name != n) {
        prev = t;
        t = t->next;
    }
    if (!t) return;

    if (prev) prev->next = t->next;
    else frontPtr = t->next;

    enqueue(n, newP);
    delete t;
}

void display() {
    Patient* t = frontPtr;
    while (t) {
        cout << t->name << " P:" << t->priority << endl;
        t = t->next;
    }
}

int main() {
    enqueue("Ali", 2);
    enqueue("Sara", 1);
    enqueue("John", 3);

    cout << "Queue:" << endl;
    display();

    upgrade("John", 1);

    cout << "After upgrade:" << endl;
    display();

    treat();

    cout << "After treat:" << endl;
    display();
}
