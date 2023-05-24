#include <iostream>
using namespace std;

int n, m, u, l, r, d;
char map[20][20];

int main() {
    cin >> n >> m >> u >> l >> r >> d;
    for (int i = u; i < u + n; i++) {
        for (int j = l; j < l + m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < u + d + n; i++) {
        for (int j = 0; j < l + r + m; j++) {
            if (map[i][j]) {
                cout << map[i][j];
                continue;
            }
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    map[i][j] = '#';
                } else {
                    map[i][j] = '.';
                }
            } else {
                if (j % 2 == 0) {
                    map[i][j] = '.';
                } else {
                    map[i][j] = '#';
                }
            }
            cout << map[i][j];
        }
        cout << '\n';
    }
}