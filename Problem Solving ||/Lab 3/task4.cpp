#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int search(Node* head, int key) {
    if(!head) return -1;

    Node* temp = head;
    int idx = 0;

    do {
        if(temp->data == key) return idx;
        temp = temp->next;
        idx++;
    } while(temp != head);

    return -1;
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

    int key;
    cout << "Search value: ";
    cin >> key;

    int pos = search(head, key);

    if(pos == -1) cout << "Not found\n";
    else cout << "Found at index: " << pos << endl;
}
