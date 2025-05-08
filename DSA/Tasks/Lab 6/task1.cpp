#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val = 0) : data(val), next(nullptr) {} 
};

class SinglyLinkedList {
private:
    Node* head; 

public:
    SinglyLinkedList() {
        head = new Node(); 
    }

    
    int size() const {
        int count = 0;
        Node* current = head->next;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

   
    void print() const {
        Node* current = head->next;
        if (!current) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Linked List: ";
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    
    bool contains(int x) const {
        Node* current = head->next;
        while (current) {
            if (current->data == x)
                return true;
            current = current->next;
        }
        return false;
    }

    
    void add(int x) {
        if (contains(x)) {
            cout << x << " already exists. Not adding.\n";
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = head->next;
        head->next = newNode;
        cout << x << " added successfully.\n";
    }

    
    void remove(int x) {
        Node* prev = head;
        Node* curr = head->next;

        while (curr) {
            if (curr->data == x) {
                prev->next = curr->next;
                delete curr;
                cout << x << " removed successfully.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << x << " not found. Nothing removed.\n";
    }
};

int main() {
    SinglyLinkedList list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.print();               
    cout << "Size: " << list.size() << endl;

    list.add(20);               
    cout << "Contains 20? " << (list.contains(20) ? "Yes" : "No") << endl;

    list.remove(20);           
    list.print();
    cout << "Size: " << list.size() << endl;

    list.remove(100);           
}