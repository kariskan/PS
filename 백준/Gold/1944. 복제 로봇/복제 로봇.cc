#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <stack>
using namespace std;

int p[2501];

int Find(int x) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = Find(p[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    p[b] = a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    char board[50][50];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'S') {
                board[i][j] = 'K';
            }
            p[i * n + j] = i * n + j;
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    vector<pair<int, pair<int, int> > > v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'K') {

                queue<pair<int, int> > q;
                int vis[50][50] = {0,};

                q.push({i, j});
                vis[i][j] = 1;

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    if ((i != x || j != y) && board[x][y] == 'K') {
                        v.push_back({vis[x][y] - 1, {i * n + j, x * n + y}});
                    }

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && board[nx][ny] != '1') {
                            vis[nx][ny] = vis[x][y] + 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    sort(v.begin(), v.end());
    int cnt = 0, ans = 0;
    for (int i = 0; i < v.size(); i++) {
        int n1 = v[i].second.first;
        int n2 = v[i].second.second;
        int cost = v[i].first;
        if (Find(n1) != Find(n2)) {
            Union(n1, n2);
            cnt++;
            ans += cost;
        }
    }

    if (cnt != m) {
        cout << -1;
    } else {
        cout << ans << '\n';
    }
}
