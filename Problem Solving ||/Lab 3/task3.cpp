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

void deleteValue(Node*& head, int key) {
    if(!head) return;

    Node* curr = head;
    Node* prev = NULL;

    do {
        if(curr->data == key) {
            if(curr == head) {
                Node* last = head;
                while(last->next != head) last = last->next;

                if(head->next == head) {
                    delete head;
                    head = NULL;
                    return;
                }

                head = head->next;
                last->next = head;
            } else {
                prev->next = curr->next;
            }

            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while(curr != head);
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
    cout << "Value to delete: ";
    cin >> key;
    deleteValue(head, key);

    cout << "After Deletion: ";
    display(head);
}
