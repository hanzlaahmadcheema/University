#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display(Node* head) {
    if(!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
    cout << endl;
}

void insertAtBegin(Node*& head, int val) {
    Node* newNode = new Node{val, NULL};

    if(!head) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next != head) temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

int main() {
    Node* head = NULL;

    int n, val;
    cout << "How many nodes? ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> val;
        insertAtBegin(head, val);
    }

    int x;
    cout << "Value to insert at beginning: ";
    cin >> x;
    insertAtBegin(head, x);

    cout << "Updated List: ";
    display(head);
}
