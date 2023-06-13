#include <iostream>
#include <cstring>
using namespace std;

int n, m, x, y, ans;
char map[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int vis[501][501][4];
bool flag = false;
char dirChar[4] = {'U', 'R', 'D', 'L'};

int getNextDir(int dir, char next) {
    if (next == '.') {
        return dir;
    }
    if (next == '/') {

        if (dir == 0) {
            return 1;
        } else if (dir == 1) {
            return 0;
        } else if (dir == 2) {
            return 3;
        }
        return 2;
    }
    if (dir == 0) {
        return 3;
    } else if (dir == 3) {
        return 0;
    } else if (dir == 1) {
        return 2;
    }
    return 1;
}

void go(int x, int y, int dir, int cnt) {
    ans = max(ans, cnt);
    vis[x][y][dir] = 1;

    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (vis[nx][ny][dir]) {
        flag = true;
        return;
    }
    if (nx > 0 && nx <= n && ny > 0 && ny <= m && map[nx][ny] != 'C') {
        dir = getNextDir(dir, map[nx][ny]);
        go(nx, ny, dir, cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    cin >> x >> y;
    int ansDir = 0;
    for (int d = 0; d < 4; d++) {
        int pre = ans;
        flag = false;
        go(x, y, d, 1);
        if (flag) {
            cout << dirChar[d] << '\n';
            cout << "Voyager";
            return 0;
        }
        if (ans > pre) {
            ansDir = d;
        }
        memset(vis, 0, sizeof(vis));
    }

    cout << dirChar[ansDir] << '\n';
    cout << ans;
}