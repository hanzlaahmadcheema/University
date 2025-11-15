#include <iostream>
using namespace std;

struct Action {
    string act;
    Action* next;
};

void push(Action*& head, string a) {
    head = new Action{a, head};
}

string pop(Action*& head) {
    if(!head) return "";
    Action* del = head;
    string val = head->act;
    head = head->next;
    delete del;
    return val;
}

int main() {
    Action* undo = NULL;
    Action* redo = NULL;

    push(undo, "Type A");
    push(undo, "Delete Word");

    string x = pop(undo);
    push(redo, x);

    string y = pop(redo);
    push(undo, y);

    return 0;
}
