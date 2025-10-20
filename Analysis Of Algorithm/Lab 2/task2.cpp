#include <iostream>
#include <string>
using namespace std;

void findPattern(string text, string pat) {
    int n = text.length(), m = pat.length();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pat[j]) break;
        }
        if (j == m) cout << "Pattern at: " << i << endl;
    }
}

int main() {
    
    int arr[5] = {1, 4, 6, 8, 10};
    
    findPattern("ABABDABACDABABCABAB", "ABAB");

    return 0;
}
