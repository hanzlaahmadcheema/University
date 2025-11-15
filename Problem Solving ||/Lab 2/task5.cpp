#include <iostream>
using namespace std;

struct Song {
    string title;
    Song* next;
};

void addSong(Song*& head, string t) {
    Song* n = new Song{t, NULL};
    if(!head) { head = n; return; }

    Song* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = n;
}

void removeSong(Song*& head, string t) {
    if(!head) return;

    if(head->title == t) {
        Song* del = head;
        head = head->next;
        delete del;
        return;
    }

    Song* temp = head;
    while(temp->next && temp->next->title != t) temp = temp->next;

    if(temp->next) {
        Song* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
}

void playNext(Song*& current) {
    if(!current) {
        cout << "No songs.\n";
        return;
    }
    cout << "Playing: " << current->title << endl;
    current = current->next;
}

int main() {
    Song* playlist = NULL;
    addSong(playlist, "Song A");
    addSong(playlist, "Song B");
    addSong(playlist, "Song C");

    Song* current = playlist;
    playNext(current);
    playNext(current);

    removeSong(playlist, "Song B");

    current = playlist;
    playNext(current);
}
