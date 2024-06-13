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

int a[100][100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            c += a[i][j];
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int ans = 0;
    while (c != 0) {
        queue<pair<int, int>> q, t;
        int vis[100][100] = {0,};

        q.push({0, 0});
        vis[0][0] = -1;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (a[nx][ny] == 0 && vis[nx][ny] != -1) {
                        q.push({nx, ny});
                        vis[nx][ny] = -1;
                    }
                    if (a[nx][ny] == 1) {
                        vis[nx][ny]++;
                        if (vis[nx][ny] >= 2) {
                            t.push({nx, ny});
                        }
                    }
                }
            }
        }
        while (!t.empty()) {
            int x = t.front().first;
            int y = t.front().second;
            t.pop();

            if (a[x][y]) {
                a[x][y] = 0;
                c--;
            }
        }
        ans++;
    }
    cout << ans;
}