#include <iostream>
#include <queue>
using namespace std;

int n, m, l, r, map[1000][1000], vis[1000][1000];
int sx, sy;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    cin >> n >> m >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
            if (map[i][j] == 2) {
                sx = i, sy = j;
                map[i][j] = 0;
            }
        }
    }

    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{sx, sy}, {0, 0}});
    vis[sx][sy] = 1;
    int ans = 0;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int nl = q.front().second.first;
        int nr = q.front().second.second;
        ans++;
        q.pop();

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            while (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != 1 &&
                !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({{nx, ny}, {nl, nr}});
                nx += dx[i];
                ny += dy[i];
            }
        }

        for (int i = 2; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != 1 &&
                !vis[nx][ny]) {
                vis[nx][ny] = 1;
                if (i == 2) { // r
                    if (nr < r) {
                        q.push({{nx, ny}, {nl, nr + 1}});
                    }
                } else { // l
                    if (nl < l) {
                        q.push({{nx, ny}, {nl + 1, nr}});
                    }
                }
            }
        }
    }

    cout << ans;
}