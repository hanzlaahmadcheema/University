#include <iostream>
using namespace std;

struct Song {
    string title;
    string artist;
    int duration;
    Song* next;
};

Song* head = NULL;

void addSong(string t, string a, int d) {
    Song* n = new Song{t, a, d, NULL};
    if (!head) {
        head = n;
        return;
    }
    Song* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}

void removeSong(string t) {
    if (!head) return;
    if (head->title == t) {
        Song* d = head;
        head = head->next;
        delete d;
        return;
    }
    Song* temp = head;
    while (temp->next && temp->next->title != t) temp = temp->next;
    if (temp->next) {
        Song* d = temp->next;
        temp->next = temp->next->next;
        delete d;
    }
}

void searchArtist(string a) {
    Song* temp = head;
    int idx = 1;
    while (temp) {
        if (temp->artist == a) {
            cout << "Found at position " << idx << endl;
        }
        temp = temp->next;
        idx++;
    }
}

int totalDuration() {
    Song* temp = head;
    int sum = 0;
    while (temp) {
        sum += temp->duration;
        temp = temp->next;
    }
    return sum;
}

void reversePlaylist() {
    Song* prev = NULL;
    Song* curr = head;
    while (curr) {
        Song* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display() {
    Song* temp = head;
    while (temp) {
        cout << temp->title << " | " << temp->artist << " | " << temp->duration << endl;
        temp = temp->next;
    }
}

int main() {
    addSong("A", "X", 200);
    addSong("B", "X", 150);
    addSong("C", "Y", 220);

    cout << "Playlist:" << endl;
    display();

    cout << "Search artist X:" << endl;
    searchArtist("X");

    cout << "Total duration: " << totalDuration() << endl;

    removeSong("B");

    cout << "After removing B:" << endl;
    display();

    reversePlaylist();

    cout << "Reversed:" << endl;
    display();
}
