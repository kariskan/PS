#include <iostream>
using namespace std;

int n, m, ans;
char map[50][50];
int r, c;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        bool row = false;
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'X') {
                row = true;
            }
        }
        if (!row) {
            r++;
        }
    }

    for (int j = 0; j < m; j++) {
        bool col = false;
        for (int i = 0; i < n; i++) {
            if (map[i][j] == 'X') {
                col = true;
            }
        }
        if (!col) {
            c++;
        }
    }

    cout << max(r, c);
}