#include <iostream>
#include <string>
using namespace std;

void permute(string s, int l, int r) {
    if (l == r) cout << s << " ";
    else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            permute(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}

int main() {
    
    string word = "DOG";
    permute(word, 0, word.length() - 1);
    cout << endl;

    return 0;
}
