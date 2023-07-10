#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = sqrt((int)s.length());
        char map[100][100] = {};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = s[i * n + j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << map[j][n - i - 1];
            }
        }
        cout << '\n';
    }
}