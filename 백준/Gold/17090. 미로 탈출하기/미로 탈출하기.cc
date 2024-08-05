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

int n, m, vis[500][500], cur, ans;
char board[500][500];

pair<int, int> next(int x, int y) {
    char dir = board[x][y];
    switch (dir) {
        case 'R': return {x, y + 1};
        case 'L': return {x, y - 1};
        case 'U': return {x - 1, y};
        default: return {x + 1, y};
    }
}

bool range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// vis[x][y] = 1이면 사이클
// vis[x][y] = 2이면 탈출 가능
void go(int x, int y) {
    vis[x][y] = 1;
    pair<int, int> nxt = next(x, y);
    int nx = nxt.first;
    int ny = nxt.second;
    if (!range(nx, ny)) {
        vis[x][y] = 2;
        cur = 2;
        return;
    }
    if (vis[nx][ny] != 0) {
        vis[x][y] = vis[nx][ny];
        cur = vis[nx][ny];
        return;
    }
    go(nx, ny);
    vis[x][y] = cur;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 0) {
                cur = 0;
                go(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 2) {
                ans++;
            }
        }
    }
    cout << ans;
}