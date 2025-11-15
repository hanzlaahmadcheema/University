#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* temp = NULL;
    Node* newNode = NULL;

    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;

        newNode = new Node{val, NULL};
        if(!head) head = newNode;
        else temp->next = newNode;
        temp = newNode;
    }

    cout << "Linked List: ";
    temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
