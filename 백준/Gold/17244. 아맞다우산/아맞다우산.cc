#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

pair<int, int> seq[5];
int n, m, sx, sy, ex, ey;
char map[50][50];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int startX, int startY, int targetX, int targetY) {
    queue<pair<int, int>> q;
    int vis[50][50] = {0};
    q.push({startX, startY});
    vis[startX][startY] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == targetX && y == targetY) {
            return vis[x][y] - 1;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != '#' &&
                !vis[nx][ny]) {
                q.push({nx, ny});
                vis[nx][ny] = vis[x][y] + 1;
            }
        }
    }
    return 0;
}

int main() {
    cin >> m >> n;
    int seqIdx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (map[i][j] == 'X') {
                seq[seqIdx++] = {i, j};
            }
            if (map[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    vector<int> v;
    for (int i = 0; i < seqIdx; i++) {
        v.push_back(i);
    }
    int ans = 1000000000;
    do {
        int res = 0;
        int tx = sx, ty = sy;
        for (int i = 0; i < v.size(); i++) {
            res += bfs(tx, ty, seq[v[i]].first, seq[v[i]].second);
            tx = seq[v[i]].first;
            ty = seq[v[i]].second;
        }
        res += bfs(tx, ty, ex, ey);
        ans = min(ans, res);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans;
}