#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        char map[11][11] = {'\0'};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << map[i][m - j - 1];
            }
            cout << '\n';
        }
    }
}