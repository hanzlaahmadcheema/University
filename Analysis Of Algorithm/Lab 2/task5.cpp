#include <iostream>
#include <string>
using namespace std;

void charFreq(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') continue;
        char c = s[i];
        int count = 1;
        for (int j = i + 1; j < s.length(); j++) {
            if (s[j] == c) { count++; s[j] = '0'; }
        }
        cout << c << "=" << count << " ";
    }
}

int main() {
   
    charFreq("MISSISSIPPI");
    cout << endl;

    return 0;
}
