#include <iostream>
using namespace std;

struct Task {
    string name;
    Task* next;
};

void addTask(Task*& head, string n) {
    Task* t = new Task{n, head};
    head = t;
}

void completeTask(Task*& head, string n) {
    if(!head) return;

    if(head->name == n) {
        Task* del = head;
        head = head->next;
        delete del;
        return;
    }

    Task* temp = head;
    while(temp->next && temp->next->name != n) temp = temp->next;

    if(temp->next) {
        Task* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
}

void showTasks(Task* head) {
    Task* t = head;
    while(t) {
        cout << t->name << endl;
        t = t->next;
    }
}

int main() {
    Task* tasks = NULL;

    addTask(tasks, "Buy groceries");
    addTask(tasks, "Study DSA");
    addTask(tasks, "Check emails");

    completeTask(tasks, "Study DSA");

    showTasks(tasks);
}
