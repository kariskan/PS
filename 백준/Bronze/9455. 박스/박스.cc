#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, map[100][100] = {0};
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
            }
        }
        queue<int> q[100];
        for (int j = 0; j < m; j++) {
            for (int i = n - 1; i >= 0; i--) {
                if (map[i][j]) {
                    q[j].push(i);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int idx = n - 1;
            while (!q[i].empty()) {
                int x = q[i].front();
                q[i].pop();
                ans += abs(idx - x);
                idx--;
            }
        }
        cout << ans << '\n';
    }
}