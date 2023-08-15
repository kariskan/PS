#include <iostream>
using namespace std;

int n, map[100][100], vis[10001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (vis[map[i][j]]) {
                cout << "FALSE";
                return 0;
            }
            vis[map[i][j]] = 1;
        }
    }
    int s = (n * (n * n + 1)) / 2;
    for (int i = 0; i < n; i++) {
        int s1 = 0, s2 = 0;
        for (int j = 0; j < n; j++) {
            s1 += map[i][j];
            s2 += map[j][i];
        }
        if (s1 != s || s2 != s) {
            cout << "FALSE";
            return 0;
        }
    }
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        s1 += map[i][i];
        s2 += map[i][n - i - 1];
    }
    if (s1 != s || s2 != s) {
        cout << "FALSE";
        return 0;
    }
    cout << "TRUE";
}