// //2. Browser History Tracking
// Scenario: A web browser needs to track user's browsing history using a singly linked list where each node represents a visited webpage.
// Problem: Create a system that:
//     • Adds new pages to history when visited
//     • Allows navigation backward through history
//     • Removes all history entries for a specific domain
//     • Implements a "clear recent history" function that removes last N entries
//     • Detects if there's a circular reference in history (infinite loop)
#include <iostream>
#include <string>
using namespace std;
struct Page {
    string url;
    Page* next;
    
    Page(const string& u) : url(u), next(nullptr) {}
};
class BrowserHistory {
private:
    Page* head;
public:
    BrowserHistory() : head(nullptr) {}
    ~BrowserHistory() {
        while (head) {
            Page* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void visitPage(const string& url) {
        Page* newPage = new Page(url);
        if (!head) {
            head = newPage;
            return;
        }
        Page* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newPage;
    }
    void goBack() {
        if (!head || !head->next) {
            cout << "No previous page in history." << endl;
            return;
        }
        Page* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
        cout << "Going back to: " << temp->url << endl;
        delete temp->next;
        temp->next = nullptr;
    }
    void removeDomain(const string& domain) {
        while (head && head->url.find(domain) != string::npos) {
            Page* temp = head;
            head = head->next;
            delete temp;
        }
        Page* current = head;
        while (current && current->next) {
            if (current->next->url.find(domain) != string::npos) {
                Page* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }
    void clearRecentHistory(int n) {
        if (n <= 0) return;
        Page* fast = head;
        Page* slow = head;
        for (int i = 0; i < n; ++i) {
            if (!fast) {
                head = nullptr;
                return;
            }
            fast = fast->next;
        }
        if (!fast) {
            head = nullptr;
            return;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        Page* temp = slow->next;;
        slow->next = nullptr;
        while (temp) {
            Page* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
    bool hasCircularReference() {
        Page* slow = head;
        Page* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
    void printHistory() {
        Page* temp = head;
        while (temp) {
            cout << temp->url << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
            prev = current;