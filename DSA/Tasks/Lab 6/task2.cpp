#include <iostream>
using namespace std;

class Mobile {
private:
    string brand;
    int unitsOnHand;
    double price;

public:
    Mobile(string b = "", int units = 0, double p = 0.0)
        : brand(b), unitsOnHand(units), price(p) {}

    
    void setBrand(string b) { brand = b; }
    void setUnits(int u) { unitsOnHand = u; }
    void setPrice(double p) { price = p; }

    
    string getBrand() const { return brand; }
    int getUnits() const { return unitsOnHand; }
    double getPrice() const { return price; }

    
    void display() const {
        cout << "Brand: " << brand
             << ", Units: " << unitsOnHand
             << ", Price: $" << price << endl;
    }
};

class Store {
private:
    struct Node {
        Mobile mobile;
        Node* next;
        Node(Mobile m) : mobile(m), next(nullptr) {}
    };
    Node* head;

public:
    Store() : head(nullptr) {}

    
    void insertAtStart(Mobile m) {
        Node* newNode = new Node(m);
        newNode->next = head;
        head = newNode;
        cout << "Inserted at start.\n";
    }
   
    void insertAtEnd(Mobile m) {
        Node* newNode = new Node(m);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted at end.\n";
    }

    
    void insertAfterBrand(string brandName, Mobile m) {
        Node* temp = head;
        while (temp) {
            if (temp->mobile.getBrand() == brandName) {
                Node* newNode = new Node(m);
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted after brand " << brandName << ".\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Brand not found. No insertion.\n";
    }

    
    void deleteFromStart() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted from start.\n";
    }

    
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next) temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
        cout << "Deleted from end.\n";
    }

    void deleteByBrand(string brandName) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (head->mobile.getBrand() == brandName) {
            deleteFromStart();
            return;
        }

        Node* prev = head;
        Node* curr = head->next;

        while (curr) {
            if (curr->mobile.getBrand() == brandName) {
                prev->next = curr->next;
                delete curr;
                cout << "Deleted brand " << brandName << ".\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Brand not found. No deletion.\n";
    }

    
    void displayAll() const {
        if (!head) {
            cout << "Store is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            temp->mobile.display();
            temp = temp->next;
        }
    }
};

int main() {
    Store s;    
    Mobile m1("Samsung", 10, 799.99);
    Mobile m2("Apple", 5, 1199.99);
    Mobile m3("OnePlus", 15, 699.99);
    Mobile m4("Xiaomi", 8, 499.99);

    s.insertAtStart(m1);
    s.insertAtEnd(m2);
    s.insertAfterBrand("Samsung", m3); 
    s.insertAfterBrand("Apple", m4);   

    cout << "\nAll Mobiles:\n";
    s.displayAll();

    s.deleteFromStart();
    s.deleteFromEnd();
    s.deleteByBrand("OnePlus");

    cout << "\nAfter Deletions:\n";
    s.displayAll();

    return 0;
}