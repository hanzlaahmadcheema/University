#include <iostream>
#include <string>
using namespace std;

void crackPassword(string pass) {
    string set = "0123456789";
    int attempts = 0;
    for (int i = 0; i < set.size(); i++) {
        string guess = "";
        guess += set[i];
        attempts++;
        if (guess == pass) { cout << "Attempts: " << attempts << endl; return; }
    }
    for (int i = 0; i < set.size(); i++) {
        for (int j = 0; j < set.size(); j++) {
            string guess = "";
            guess += set[i]; guess += set[j];
            attempts++;
            if (guess == pass) { cout << "Attempts: " << attempts << endl; return; }
        }
    }
    for (int i = 0; i < set.size(); i++) {
        for (int j = 0; j < set.size(); j++) {
            for (int k = 0; k < set.size(); k++) {
                string guess = "";
                guess += set[i]; guess += set[j]; guess += set[k];
                attempts++;
                if (guess == pass) { cout << "Attempts: " << attempts << endl; return; }
            }
        }
    }
}

int main() {

    crackPassword("23");
    
    return 0;
}
