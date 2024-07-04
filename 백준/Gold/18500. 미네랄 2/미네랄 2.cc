#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

char board[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool compare(pair<int, int> &p1, pair<int, int> &p2) {
    return p1.first > p2.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    int c;
    cin >> c;
    for (int l = 0; l < c; l++) {
        int a;
        cin >> a;

        if (l % 2 == 0) {
            for (int j = 1; j <= m; j++) {
                if (board[n - a + 1][j] == 'x') {
                    board[n - a + 1][j] = '.';
                    break;
                }
            }
        } else {
            for (int j = m; j >= 1; j--) {
                if (board[n - a + 1][j] == 'x') {
                    board[n - a + 1][j] = '.';
                    break;
                }
            }
        }

        int vis[101][101] = {0,};
        int visIdx = 0;
        bool brk = false;
        queue<pair<int, int> > q;
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int j = 1; j <= m; j++) {
                if (board[i][j] == '.' || vis[i][j]) {
                    continue;
                }
                vector<pair<int, int> > v;
                q.push({i, j});
                visIdx++;
                vis[i][j] = visIdx;
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    v.push_back({x, y});
                    if (x == n) {
                        flag = false;
                    }

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && vis[nx][ny] == 0 && board[nx][ny] == 'x') {
                            vis[nx][ny] = visIdx;
                            q.push({nx, ny});
                        }
                    }
                }
                if (flag) {
                    int dropHeight = n;
                    for (int k = 0; k < v.size(); k++) {
                        int x = v[k].first;
                        int y = v[k].second;
                        int idx = x;
                        while (1) {
                            idx++;
                            if (idx > n || (vis[x][y] != vis[idx][y] && board[idx][y] == 'x')) {
                                break;
                            }
                        }
                        if (idx > n) {
                            dropHeight = min(dropHeight, n - x);
                            // cout << x << ' ' << idx << '\n';
                        } else {
                            dropHeight = min(dropHeight, idx - x - 1);
                            // cout << x << ' ' << idx << '\n';
                        }
                    }
                    // cout << dropHeight << '\n';
                    sort(v.begin(), v.end(), compare);
                    for (int i = 0; i < v.size(); i++) {
                        int x = v[i].first;
                        int y = v[i].second;
                        board[x + dropHeight][y] = 'x';
                        board[x][y] = '.';
                        // cout << x << ' ' << y << ' ' << x + dropHeight << ' ' << y << '\n';
                    }
                    brk = true;
                    break;
                }
            }
            if (brk) {
                break;
            }
        }
        // for (int i = 1; i <= n; i++) {
            // for (int j = 1; j <= m; j++) {
                // cout << board[i][j];
            // }
            // cout << '\n';
        // }
        // cout << '\n';
        // for (int i = 1; i <= n; i++) {
            // for (int j = 1; j <= m; j++) {
                // cout << vis[i][j];
            // }
            // cout << '\n';
        // }
        // cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}
// 11 12 12 7