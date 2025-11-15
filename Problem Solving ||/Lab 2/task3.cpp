#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteKey(Node*& head, int key) {
    if(!head) return;

    if(head->data == key) {
        Node* del = head;
        head = head->next;
        delete del;
        return;
    }

    Node* temp = head;
    while(temp->next && temp->next->data != key) {
        temp = temp->next;
    }

    if(temp->next) {
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
}

int main() {
    Node* head = NULL;
    Node* temp = NULL;

    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> val;
        Node* newNode = new Node{val, NULL};
        if(!head) head = newNode;
        else temp->next = newNode;
        temp = newNode;
    }

    int key;
    cout << "Enter key to delete: ";
    cin >> key;

    deleteKey(head, key);

    cout << "List after deletion: ";
    temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
