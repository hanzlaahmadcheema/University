// //1. Music Playlist Management
// Scenario: You're building a music player that needs to manage playlists using singly linked lists. Each song is a node containing song title, artist, and duration.
// Problem: Implement functions to:
//     • Add songs to the end of playlist
//     • Remove a specific song by title
//     • Search for songs by artist
//     • Calculate total playlist duration
//     • Reverse the playlist (play songs in reverse order)
// Challenge: Handle cases where multiple songs have the same title or artist.
#include <iostream>
#include <string>
using namespace std;
struct Song {
    string title;
    string artist;
    int duration; // duration in seconds
    Song* next;
    
    Song(string t, string a, int d) : title(t), artist(a), duration(d), next(nullptr) {}
};
class Playlist {
private:
    Song* head;
public:
    Playlist() : head(nullptr) {}
    ~Playlist() {
        while (head) {
            Song* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void addSong(const string& title, const string& artist, int duration) {
        Song* newSong = new Song(title, artist, duration);
        if (!head) {
            head = newSong;
            return;
        }
        Song* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
    void removeSong(const string& title) {
        while (head && head->title == title) {
            Song* temp = head;
            head = head->next;
            delete temp;
        }
        Song* current = head;
        while (current && current->next) {
            if (current->next->title == title) {
                Song* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }
    void searchByArtist(const string& artist) {
        Song* temp = head;
        while (temp) {
            if (temp->artist == artist) {
                cout << "Found: " << temp->title << " by " << temp->artist << " (" << temp->duration << "s)" << endl;
            }
            temp = temp->next;
        }
    }
    int totalDuration() {
        int total = 0;
        Song* temp = head;
        while (temp) {
            total += temp->duration;
            temp = temp->next;
        }
        return total;
    }
    void reversePlaylist() {
        Song* prev = nullptr;
        Song* current = head;
        Song* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void displayPlaylist() {
        Song* temp = head;
        while (temp) {
            cout << temp->title << " by " << temp->artist << " (" << temp->duration << "s)" << endl;
            temp = temp->next;
        }
    }
};
int main() {
    Playlist myPlaylist;
    myPlaylist.addSong("Song1", "Artist1", 210);
    myPlaylist.addSong("Song2", "Artist2", 180);
    myPlaylist.addSong("Song1", "Artist3", 200);
    myPlaylist.addSong("Song3", "Artist1", 240);
    cout << "Playlist:" << endl;
    myPlaylist.displayPlaylist();
    cout << "Total Duration: " << myPlaylist.totalDuration() << " seconds" << endl;
    cout << "Searching for songs by Artist1:" << endl;
    myPlaylist.searchByArtist("Artist1");
    myPlaylist.removeSong("Song1");
    cout << "Playlist after removing 'Song1':" << endl;
    myPlaylist.displayPlaylist();
    myPlaylist.reversePlaylist();
    cout << "Reversed Playlist:" << endl;
    myPlaylist.displayPlaylist();
    return 0;
}