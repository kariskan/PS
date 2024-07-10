#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n, m;
    cin >> n >> m;
    vector<vector<int> > board(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < m; y1++) {
            for (int x2 = x1; x2 < n; x2++) {
                for (int y2 = 0; y2 < m; y2++) {
                    if (x1 == x2 && y1 == y2) {
                        continue;
                    }
                    if (board[x1][y1] == 0 && board[x2][y2] == 0) {
                        board[x1][y1] = board[x2][y2] = 1;
                        int killCount = 0;
                        int vis[20][20] = {0,};
                        queue<pair<int, int> > q;
                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < m; j++) {
                                if (!vis[i][j] && board[i][j] == 2) {
                                    bool flag = true;
                                    vis[i][j] = 1;
                                    q.push({i, j});
                                    int enemyCount = 0;
                                    while (!q.empty()) {
                                        int x = q.front().first;
                                        int y = q.front().second;
                                        q.pop();

                                        enemyCount++;

                                        for (int k = 0; k < 4; k++) {
                                            int nx = x + dx[k];
                                            int ny = y + dy[k];
                                            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                                                if (board[nx][ny] == 0) {
                                                    flag = false;
                                                }
                                                if (!vis[nx][ny] && board[nx][ny] == 2) {
                                                    vis[nx][ny] = 1;
                                                    q.push({nx, ny});
                                                }
                                            }
                                        }
                                    }
                                    if (flag) {
                                        killCount += enemyCount;
                                    }
                                }
                            }
                        }
                        ans = max(ans, killCount);
                        board[x1][y1] = board[x2][y2] = 0;
                    }
                }
            }
        }
    }

    cout << ans;
}
