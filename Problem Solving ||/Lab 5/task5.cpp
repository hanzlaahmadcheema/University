#include <iostream>
using namespace std;

struct Player {
    string name;
    Player* next;
};

Player* head = NULL;

void addPlayer(string n) {
    Player* p = new Player{n, NULL};
    if (!head) {
        head = p;
        p->next = p;
        return;
    }
    Player* t = head;
    while (t->next != head) t = t->next;
    t->next = p;
    p->next = head;
}

void removePlayer(string n) {
    if (!head) return;
    Player* t = head;
    Player* p = NULL;
    do {
        if (t->name == n) break;
        p = t;
        t = t->next;
    } while (t != head);

    if (t->name != n) return;

    if (t == head && head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    if (t == head) head = head->next;
    p->next = t->next;
    delete t;
}

void display() {
    if (!head) return;
    Player* t = head;
    do {
        cout << t->name << endl;
        t = t->next;
    } while (t != head);
}

int main() {
    addPlayer("Ali");
    addPlayer("Sara");
    addPlayer("John");

    cout << "Players:" << endl;
    display();

    removePlayer("Sara");

    cout << "After removal:" << endl;
    display();
}
