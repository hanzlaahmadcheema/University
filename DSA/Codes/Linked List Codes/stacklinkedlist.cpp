/*
Using a Linked List to Implement a Stack
Instead of using an array, this implementation uses a linked list, which allows dynamic memory allocation (the stack size can grow or shrink as needed).

Each element in the stack is represented by a node. Each node contains:

A data field to store the value.

A pointer (or reference) to the next node in the stack.

The stack class maintains a pointer to the top node, which is the most recently added item.

Core Functionality Explained
1. Initialization
When the stack is created, it is empty, so the top pointer is set to null.

2. Push Operation
When a new value is pushed onto the stack:

A new node is created.

The node’s next pointer is set to the current top node.

The top pointer is updated to this new node.

This means the new value is now at the top of the stack.

3. Pop Operation
To remove the top value:

The stack is first checked to ensure it's not empty.

The top pointer is moved to the next node.

The previous top node is deleted (freed from memory).

This removes the most recent item added.

4. Peek Operation
This returns the value at the top of the stack without removing it.

If the stack is empty, it returns a message or an error value.

5. isEmpty Check
This function simply checks if the top pointer is null.

If it is, the stack has no elements.

6. Display Function
This prints all elements from top to bottom by traversing the linked list starting from the top node.

7. Destructor
When the stack object is destroyed (e.g., when the program ends), the destructor removes all nodes one by one to prevent memory leaks.*/
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Stack class using linked list
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack.\n";
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped from stack.\n";
        delete temp;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Main function
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();
    s.display();

    cout << "Top element is: " << s.peek() << endl;

    return 0;
}