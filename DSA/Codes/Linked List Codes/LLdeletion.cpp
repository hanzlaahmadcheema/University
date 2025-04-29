#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a node at the end of the linked list
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the beginning of the linked list
void deleteBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to delete a node from the end of the linked list
void deleteEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

// Function to delete a node at a specific position
void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr || position <= 0) {
        cout << "Position is out of bounds or list is empty.\n";
        return;
    }

    if (position == 1) {
        deleteBeginning(head);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Position is out of bounds.\n";
    } else {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
}

// Function to delete a node by its value
void deleteByValue(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == value) {
        deleteBeginning(head);
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Value " << value << " not found in the list.\n";
    } else {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
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

    // Insert nodes at the end for demonstration
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);

    cout << "Initial list: ";
    displayList(head);

    // Delete from the beginning
    deleteBeginning(head);
    cout << "After deleting from the beginning: ";
    displayList(head);

    // Delete from the end
    deleteEnd(head);
    cout << "After deleting from the end: ";
    displayList(head);

    // Delete at a specific position
    deleteAtPosition(head, 2); // Deletes the 2nd node
    cout << "After deleting at position 2: ";
    displayList(head);

    // Delete by value
    deleteByValue(head, 30);
    cout << "After deleting node with value 30: ";
    displayList(head);

    return 0;
}
