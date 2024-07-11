#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <mutex>
using namespace std;

char board[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;

bool range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool canNotRotate(int d, int nd) {
    return nd == (d + 2) % 4;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    int sx = -1, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'C') {
                if (sx == -1) {
                    sx = i;
                    sy = j;
                } else {
                    ex = i;
                    ey = j;
                }
                board[i][j] = '.';
            }
        }
    }

    int vis[100][100][4];
    queue<pair<pair<int, int>, int> > q;

    for (int i = 0; i < 4; i++) {
        vis[sx][sy][i] = 1;
        q.push({{sx, sy}, i});
    }

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nd = k;
            if (canNotRotate(d, nd)) {
                continue;
            }
            int nv = (d == nd) ? vis[x][y][d] : vis[x][y][d] + 1;
            if (range(nx, ny) && (vis[nx][ny][nd] == 0 || vis[nx][ny][nd] > nv) && board[nx][ny] != '*') {
                vis[nx][ny][nd] = nv;
                q.push({{nx, ny}, nd});
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < 4; i++) {
        if (vis[ex][ey][i] == 0) {
            continue;
        }
        ans = min(ans, vis[ex][ey][i]);
    }
    cout << ans - 1;
}
