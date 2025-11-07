// 4. Navigation System for Delivery Routes
// Scenario: A delivery company uses doubly linked list to manage delivery routes where each node represents a delivery location.
// Problem: Design a system that:
//     • Adds new delivery locations
//     • Removes completed deliveries
//     • Allows moving forward and backward through route
//     • Swaps two consecutive deliveries
//     • Calculates optimal route by reordering deliveries
#include <iostream>
#include <string>
using namespace std;
struct Location {
    string address;
    Location* prev;
    Location* next;
    Location(const string& addr) : address(addr), prev(nullptr), next(nullptr) {}
};
class DeliveryRoute {
private:
    Location* head;
    Location* tail;
public:
    DeliveryRoute() : head(nullptr), tail(nullptr) {}
    ~DeliveryRoute() {
        while (head) {
            Location* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void addLocation(const string& address) {
        Location* newLocation = new Location(address);
        if (!head) {
            head = tail = newLocation;
            return;
        }
        tail->next = newLocation;
        newLocation->prev = tail;
        tail = newLocation;
    }
    void removeLocation(const string& address) {
        Location* current = head;
        while (current) {
            if (current->address == address) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }
    void moveForward() {
        if (!head) {
            cout << "No locations in the route." << endl;
            return;
        }
        Location* current = head;
        while (current->next) {
            cout << "Visiting: " << current->address << endl;
            current = current->next;
        }
        cout << "Visiting: " << current->address << endl;
    }
    void moveBackward() {
        if (!tail) {
            cout << "No locations in the route." << endl;
            return;
        }
        Location* current = tail;
        while (current->prev) {
            cout << "Visiting: " << current->address << endl;
            current = current->prev;
        }
        cout << "Visiting: " << current->address << endl;
    }
    void swapConsecutive(const string& addr1, const string& addr2) {
        Location* first = head;;
        while (first && first->next) {
            if (first->address == addr1 && first->next->address == addr2) {
                Location* second = first->next;
                first->next = second->next;
                second->prev = first->prev;
                if (second->next) {
                    second->next->prev = first;
                } else {
                    tail = first;
                }
                second->next = first;
                first->prev = second;
                if (second->prev) {
                    second->prev->next = second;
                } else {
                    head = second;
                }
                return;
            }
            first = first->next;
        }
    }
    void printRoute() {
        Location* current = head;
        while (current) {
            cout << current->address << " -> ";
            current = current->next;
        }
        cout << "END" << endl;
    }
};
int main() {
    DeliveryRoute route;
    route.addLocation("123 Main St");
    route.addLocation("456 Oak Ave");
    route.addLocation("789 Pine Rd");
    cout << "Initial Route:" << endl;
    route.printRoute();
    cout << "\nMoving Forward through Route:" << endl;
    route.moveForward();
    cout << "\nMoving Backward through Route:" << endl;
    route.moveBackward();
    cout << "\nSwapping '456 Oak Ave' and '789 Pine Rd':" << endl;
    route.swapConsecutive("456 Oak Ave", "789 Pine Rd");
    route.printRoute();
    cout << "\nRemoving '123 Main St':" << endl;
    route.removeLocation("123 Main St");
    route.printRoute();
    return 0;
}