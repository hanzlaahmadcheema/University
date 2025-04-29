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

// Insert a node at the end of the list (helper function for setup)
void insertAtEnd(Node*& head, Node*& tail, int val) {
    Node* newNode = createNode(val);
    if (tail == nullptr) { // List is empty
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Delete the first node
void deleteAtStart(Node*& head, Node*& tail) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else { // List had only one element
        tail = nullptr;
    }
    delete temp;
}

// Delete the last node
void deleteAtEnd(Node*& head, Node*& tail) {
    if (tail == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else { // List had only one element
        head = nullptr;
    }
    delete temp;
}

// Delete a node at a specific position
void deleteAtPosition(Node*& head, Node*& tail, int position) {
    if (position <= 1) { // Delete the first node if position is <= 1
        deleteAtStart(head, tail);
        return;
    }

    Node* current = head;
    int index = 1;

    // Traverse to the specified position
    while (current != nullptr && index < position) {
        current = current->next;
        index++;
    }

    if (current == nullptr) { // Position is out of bounds
        cout << "Position " << position << " is out of bounds.\n";
        return;
    }

    if (current == tail) { // Node to be deleted is the last node
        deleteAtEnd(head, tail);
    } else { // Node is in the middle
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
}

// Display the list from start to end
void displayForward(Node* head) {
    Node* current = head;
    cout << "List (forward): ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Display the list from end to start
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

    // Insert nodes at the end
    insertAtEnd(head, tail, 10);
    insertAtEnd(head, tail, 20);
    insertAtEnd(head, tail, 30);
    insertAtEnd(head, tail, 40);
    insertAtEnd(head, tail, 50);

    // Display the initial list
    displayForward(head);
    displayBackward(tail);

    // Delete at the start
    deleteAtStart(head, tail);
    displayForward(head);
    displayBackward(tail);

    // Delete at the end
    deleteAtEnd(head, tail);
    displayForward(head);
    displayBackward(tail);

    // Delete at a specific position
    deleteAtPosition(head, tail, 2); // Deletes the node at position 2
    displayForward(head);
    displayBackward(tail);

    return 0;
}
