#include <iostream>
using namespace std;

// Node structure for a doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Insert a node at the front of the list
void insertAtFront(Node*& head, Node*& tail, int val) {
    Node* newNode = createNode(val);
    if (head == nullptr) { // List is empty
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert a node at the end of the list
void insertAtBack(Node*& head, Node*& tail, int val) {
    Node* newNode = createNode(val);
    if (tail == nullptr) { // List is empty
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Delete a node with a given value
void deleteNode(Node*& head, Node*& tail, int val) {
    Node* current = head;
    while (current != nullptr && current->data != val) {
        current = current->next;
    }
    if (current == nullptr) { // Node not found
        cout << "Value " << val << " not found in the list.\n";
        return;
    }
    if (current == head) { // Node is at the head
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        else tail = nullptr; // List is now empty
    } else if (current == tail) { // Node is at the tail
        tail = tail->prev;
        if (tail != nullptr) tail->next = nullptr;
        else head = nullptr; // List is now empty
    } else { // Node is in the middle
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    delete current;
}

// Display the list from the front to the back
void displayForward(Node* head) {
    Node* current = head;
    cout << "List (forward): ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Display the list from the back to the front
void displayBackward(Node* tail) {
    Node* current = tail;
    cout << "List (backward): ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Inserting nodes at the front
    insertAtFront(head, tail, 10);
    insertAtFront(head, tail, 20);
    insertAtFront(head, tail, 30);

    // Inserting nodes at the back
    insertAtBack(head, tail, 40);
    insertAtBack(head, tail, 50);

    // Display the list in both directions
    displayForward(head);
    displayBackward(tail);

    // Deleting a node
    deleteNode(head, tail, 20);
    displayForward(head);
    displayBackward(tail);

    return 0;
}
