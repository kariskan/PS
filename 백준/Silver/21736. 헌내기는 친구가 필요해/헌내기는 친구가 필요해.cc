#include <iostream>
#include <queue>
using namespace std;

int n, m, ans, vis[600][600];
char map[600][600];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'I') {
                x = i;
                y = j;
            }
        }
    }

    queue<pair<int, int>> q;
    vis[x][y] = 1;
    q.push({x, y});

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if (map[i][j] == 'P') {
            ans++;
        }

        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
                map[nx][ny] != 'X') {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    if (ans) {
        cout << ans;
    } else {
        cout << "TT";
    }
}