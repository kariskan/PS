#include <iostream>
#include <queue>
using namespace std;

int n, m, sx, sy, ex, ey;
char map[500][500];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int vis[500][500];

int main() {
    cin >> n >> m;
    queue<pair<int, int>> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'V') {
                sx = i;
                sy = j;
                map[i][j] = '.';
            } else if (map[i][j] == 'J') {
                ex = i;
                ey = j;
                map[i][j] = '.';
            } else if (map[i][j] == '+') {
                t.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    while (!t.empty()) {
        int x = t.front().first;
        int y = t.front().second;
        t.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '.' && !vis[nx][ny]) {
                vis[nx][ny] = vis[x][y] + 1;
                t.push({nx, ny});
            }
        }
    }
    vector<vector<pair<int, int>>> v(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    v[i * m + j].push_back(
                        {nx * m + ny, min(vis[i][j], vis[nx][ny])});
                }
            }
        }
    }

    vector<int> dis(250000, 0);
    priority_queue<pair<int, int>> pq;
    dis[sx * m + sy] = vis[sx][sy];
    pq.push({vis[sx][sy], sx * m + sy});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second / m;
        int y = pq.top().second % m;
        pq.pop();

        if (x == ex && y == ey) {
            cout << cost - 1;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nxCost = min(cost, vis[nx][ny]);
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dis[nx * m + ny] < nxCost) {
                dis[nx * m + ny] = nxCost;
                pq.push({nxCost, nx * m + ny});
            }
        }
    }
}