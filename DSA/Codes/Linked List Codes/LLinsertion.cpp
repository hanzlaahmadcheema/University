#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;  // Allocate memory for a new node
    newNode->data = value;     // Set the data for the new node
    newNode->next = nullptr;   // Initialize the next pointer to nullptr
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertBeginning(Node*& head, int value) {
    Node* newNode = createNode(value); // Create a new node with the given value
    newNode->next = head;              // Point new node's next to current head
    head = newNode;                    // Update head to the new node
}

// Function to insert a node at the end of the linked list
void insertEnd(Node*& head, int value) {
    Node* newNode = createNode(value); // Create a new node with the given value

    if (head == nullptr) {
        // If the list is empty, new node becomes the head
        head = newNode;
    } else {
        // Traverse to the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;  // Link last node to the new node
    }
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(Node*& head, int value, int position) {
    Node* newNode = createNode(value); // Create a new node with the given value

    if (position <= 0) {
        cout << "Position should be greater than 0.\n";
        delete newNode;
        return;
    }

    if (position == 1) {
        // Inserting at the beginning if position is 1
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;  // Traverse to the node just before the target position
    }

    if (temp == nullptr) {
        cout << "Position is out of bounds.\n";
        delete newNode;
    } else {
        // Insert the new node at the target position
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    // Insert nodes at the beginning
    insertBeginning(head, 10);
    insertBeginning(head, 20);
    cout << "List after inserting at the beginning: ";
    displayList(head);

    // Insert nodes at the end
    insertEnd(head, 30);
    insertEnd(head, 40);
    cout << "List after inserting at the end: ";
    displayList(head);

    // Insert at specific positions
    insertAtPosition(head, 25, 3);
    cout << "List after inserting 25 at position 3: ";
    displayList(head);

    insertAtPosition(head, 15, 2);
    cout << "List after inserting 15 at position 2: ";
    displayList(head);

    insertAtPosition(head, 5, 1);
    cout << "List after inserting 5 at position 1: ";
    displayList(head);

    return 0;
}
