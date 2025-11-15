#include <iostream>
using namespace std;

struct State {
    string data;
    State* prev;
    State* next;
};

State* current = NULL;

void save(string d) {
    State* n = new State{d, current, NULL};
    if (current) current->next = n;
    current = n;
}

void undo() {
    if (current && current->prev) current = current->prev;
}

void redo() {
    if (current && current->next) current = current->next;
}

int main() {
    save("A");
    save("B");
    save("C");

    undo(); 
    cout << "After undo: " << current->data << endl;

    redo();
    cout << "After redo: " << current->data << endl;

    save("D"); 
    cout << "After new save: " << current->data << endl;
}
