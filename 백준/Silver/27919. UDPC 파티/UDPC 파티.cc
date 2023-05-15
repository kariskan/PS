#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int u = 0, d = 0, p = 0, c = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'U') {
            u++;
        } else if (s[i] == 'D') {
            d++;
        } else if (s[i] == 'P') {
            p++;
        } else {
            c++;
        }
    }

    if (u + c > (d + p + 1) / 2) {
        cout << "U";
    }
    if (d || p) {
        cout << "DP";
    }
}