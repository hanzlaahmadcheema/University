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

int main() {
    Node* head = NULL;
    Node* temp = NULL;

    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;

        Node* newNode = new Node{val, NULL};

        if(!head) {
            head = newNode;
            head->next = head;
            temp = head;
        } else {
            newNode->next = head;
            temp->next = newNode;
            temp = newNode;
        }
    }

    cout << "Circular Linked List: ";
    display(head);
}
