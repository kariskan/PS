#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        char map[401][401] = {0};
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> map[i][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (map[i][j] == 'o') {
                    if ((map[i][j - 1] == '>' && map[i][j + 1] == '<') ||
                        (map[i - 1][j] == 'v' && map[i + 1][j] == '^')) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}