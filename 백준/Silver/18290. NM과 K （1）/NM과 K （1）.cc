#include <iostream>

using namespace std;

int n, m, k, map[10][10], ans = -1000000, vis[10][10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void go(int cnt, int sum) {
    if (cnt == k) {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) {
                continue;
            }
            bool flag = true;
            for (int t = 0; t < 4; t++) {
                int nx = i + dx[t];
                int ny = j + dy[t];
                if (!(nx >= 0 && nx < n && ny >= 0 && ny < m)) {
                    continue;
                }
                if (vis[nx][ny]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                vis[i][j] = 1;
                go(cnt + 1, sum + map[i][j]);
                vis[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    go(0, 0);
    cout << ans;
}