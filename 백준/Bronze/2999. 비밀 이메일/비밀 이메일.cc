#include <iostream>
using namespace std;
char map[101][101];
int main() {
    string s;
    cin >> s;
    int r = 0, c = 0;
    for (int i = s.length() / 2; i >= 1; i--) {
        if (s.length() % i == 0 && min((int)s.length() / i, i) > r) {
            r = min((int)s.length() / i, i);
            c = max((int)s.length() / i, i);
        }
    }
    int idx = 0;
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            map[i][j] = s[idx++];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << map[i][j];
        }
    }
}