#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display(Node* head) {
    if(!head) return;
    Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while(t != head);
    cout << endl;
}

void reverse(Node*& head) {
    if(!head || head->next == head) return;

    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while(curr != head);

    head->next = prev;
    head = prev;
}

int main() {
    Node* head = NULL;
    Node* last = NULL;

    int n, val;
    cout << "Enter nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> val;
        Node* node = new Node{val, NULL};
        if(!head) {
            head = node;
            head->next = head;
            last = head;
        } else {
            node->next = head;
            last->next = node;
            last = node;
        }
    }

    reverse(head);
    cout << "Reversed List: ";
    display(head);
}
