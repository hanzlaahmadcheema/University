#include <iostream>
using namespace std;

struct Node {
    string place;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void add(string p) {
    Node* n = new Node{p, NULL, NULL};
    if (!head) {
        head = n;
        return;
    }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void removeLoc(string p) {
    if (!head) return;
    Node* t = head;
    while (t && t->place != p) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    if (t->next) t->next->prev = t->prev;
    if (t == head) head = t->next;
    delete t;
}

void swapNext(string p) {
    Node* t = head;
    while (t && t->next && t->place != p) t = t->next;
    if (!t || !t->next) return;
    Node* a = t;
    Node* b = t->next;
    a->next = b->next;
    if (b->next) b->next->prev = a;
    b->prev = a->prev;
    b->next = a;
    if (a->prev) a->prev->next = b;
    a->prev = b;
    if (head == a) head = b;
}

void display() {
    Node* t = head;
    while (t) {
        cout << t->place << endl;
        t = t->next;
    }
}

int main() {
    add("A");
    add("B");
    add("C");

    cout << "Route:" << endl;
    display();

    swapNext("A");

    cout << "After swap:" << endl;
    display();
}
