#include <iostream>
using namespace std;

struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;  // Allocate memory for a new node
    newNode->data = value;     // Set the node's data
    newNode->next = nullptr;   // Initialize next pointer to nullptr
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertEnd(Node*& head, int value) {
    Node* newNode = createNode(value);  // Create a new node with given value

    if (head == nullptr) {
        // If the list is empty, new node becomes the head
        head = newNode;
    } else {
        // Traverse to the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Link the last node to the new node
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

// Function to delete all nodes in the linked list and free memory
void deleteList(Node*& head) {
    Node* temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = nullptr;  // Set head to nullptr after deletion
}

int main() {
    Node* head = nullptr;  // Initialize an empty linked list

    // Insert some nodes
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);

    // Display the list
    cout << "Linked List: ";
    displayList(head);

    // Clean up memory
    deleteList(head);

    return 0;
}