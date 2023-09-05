#include <iostream>
#include <queue>
using namespace std;

int n, m, map[1001][1001];
int vis[1001][1001], vis2[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    cin >> n >> m;
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if (map[i][j] > 0) {
                q.push({i, j});
                vis[i][j] = map[i][j];
                vis2[i][j] = 1;
            }
        }
    }
    int time = 1;
    while (!q.empty()) {
        int siz = q.size();
        time++;
        for (int i = 0; i < siz; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (vis[x][y] == 3) {
                continue;
            }
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (vis[nx][ny] != 3 && nx >= 1 && nx <= n && ny >= 1 && ny <= m &&
                    map[nx][ny] != -1 && (vis2[nx][ny] == 0 || vis2[nx][ny] == time)) {
                    if (vis[nx][ny] == 0) {
                        vis[nx][ny] = vis[x][y];
                        vis2[nx][ny] = time;
                        q.push({nx, ny});
                    } else {
                        if (vis[nx][ny] != vis[x][y]) {
                            vis[nx][ny] = 3;
                            vis2[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }
    int a = 0, b = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j] == 1) {
                a++;
            } else if (vis[i][j] == 2) {
                b++;
            } else if (vis[i][j] == 3) {
                c++;
            }
        }
    }
    cout << a << ' ' << b << ' ' << c;
}