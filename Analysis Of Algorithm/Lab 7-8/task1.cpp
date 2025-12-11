#include <iostream>
using namespace std;

int main() {
    string target = "4821";
    int attempts = 0;

    for (int i = 0; i <= 9999; i++) {
        attempts++;

        
        char pin[5];
        pin[0] = (i / 1000) % 10 + '0';
        pin[1] = (i / 100) % 10 + '0';
        pin[2] = (i / 10) % 10 + '0';
        pin[3] = i % 10 + '0';
        pin[4] = '\0';

        if (target[0]==pin[0] && target[1]==pin[1] && target[2]==pin[2] && target[3]==pin[3]) {
            cout << "Found PIN: " << pin << endl;
            cout << "Attempts needed: " << attempts << endl;
            break;
        }
    }

    return 0;
}
