#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int a[50][50], n, m, ans = -1, blank;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> v;

bool range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void go(vector<pair<int, int>> seq, int idx) {
    if (seq.size() == m) {
        int vis[50][50] = {0,};
        queue<pair<int, int>> q;
        for (auto &i: seq) {
            q.push({i.first, i.second});
            vis[i.first][i.second] = 1;
        }

        int ma = 0, b = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (a[x][y] == 0) {
                b++;
            }
            if (a[x][y] != 2) {
                ma = max(ma, vis[x][y] - 1);
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (range(nx, ny) && (vis[nx][ny] == 0 || vis[nx][ny] > vis[x][y] + 1) && a[nx][ny] != 1) {
                    q.push({nx, ny});
                    vis[nx][ny] = vis[x][y] + 1;
                }
            }
        }
        if (b == blank && (ans == -1 || ans > ma)) {
            if (ma == 0) {
                ans = 0;
            } else {
                ans = ma;
            }
        }
        return;
    }
    if (idx >= v.size()) {
        return;
    }
    go(seq, idx + 1);
    seq.push_back(v[idx]);
    go(seq, idx + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                v.push_back({i, j});
            }
            if (a[i][j] == 0) {
                blank++;
            }
        }
    }

    go({}, 0);
    cout << ans;
}