#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

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

    int oldVal, newVal;
    cout << "Enter value to update: ";
    cin >> oldVal;
    cout << "Enter new value: ";
    cin >> newVal;

    temp = head;
    while(temp) {
        if(temp->data == oldVal) {
            temp->data = newVal;
            break;
        }
        temp = temp->next;
    }

    cout << "Updated List: ";
    temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
