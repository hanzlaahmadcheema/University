#include <iostream>
using namespace std;

struct Page {
    string url;
    Page* next;
};

Page* head = NULL;

void visit(string u) {
    Page* n = new Page{u, head};
    head = n;
}

void back() {
    if (!head) return;
    Page* d = head;
    head = head->next;
    delete d;
}

bool matchDomain(string url, string domain) {
    return url.find(domain) != string::npos;
}

void removeDomain(string domain) {
    while (head && matchDomain(head->url, domain)) {
        Page* d = head;
        head = head->next;
        delete d;
    }
    Page* temp = head;
    while (temp && temp->next) {
        if (matchDomain(temp->next->url, domain)) {
            Page* d = temp->next;
            temp->next = temp->next->next;
            delete d;
        } else temp = temp->next;
    }
}

void clearRecent(int n) {
    while (n-- > 0 && head) back();
}

bool detectCircular() {
    Page* slow = head;
    Page* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

void display() {
    Page* t = head;
    while (t) {
        cout << t->url << endl;
        t = t->next;
    }
}

int main() {
    visit("google.com");
    visit("facebook.com");
    visit("news.bbc.com");
    visit("mail.google.com");

    cout << "History:" << endl;
    display();

    removeDomain("google");

    cout << "After removing google domain:" << endl;
    display();

    clearRecent(1);

    cout << "After clearing recent 1:" << endl;
    display();

    cout << "Circular: " << detectCircular();
}
