#include <iostream>
using namespace std;

int map[11][11], ans[111][111];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                for (int l = 1; l <= m; l++) {
                    ans[(i - 1) * m + k][(j - 1) * m + l] = map[i][j];
                }
            }
        }
    }

    for (int i = 1; i <= n * m; i++) {
        for (int j = 1; j <= n * m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}