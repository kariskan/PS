#include <iostream>
using namespace std;

int n, m, map[2000][2000], ans[4][2000][2000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int changeDir(int now, int dir) {
    if (now == 1) {
        if (dir == 0 || dir == 2) {
            return 2 - dir;
        } else {
            return dir;
        }
    }
    if (now == 2) {
        if (dir == 1) {
            return 3;
        } else if (dir == 0 || dir == 2) {
            return dir;
        } else {
            return 1;
        }
    }
    if (now == 3) {
        if (dir == 0) {
            return 3;
        } else if (dir == 1) {
            return 2;
        } else if (dir == 2) {
            return 1;
        }
        return 0;
    }
    if (now == 4) {
        if (dir == 0) {
            return 1;
        } else if (dir == 1) {
            return 0;
        } else if (dir == 2) {
            return 3;
        }
        return 2;
    }
    return dir;
}

void go(int x, int y, int dir) {
    if (!(x >= 0 && x < n && y >= 0 && y < m)) {
        return;
    }
    if (ans[dir][x][y]) {
        return;
    }
    ans[dir][x][y] = 1;

    int nd = changeDir(map[x][y], dir);
    // cout << x << ' ' << y << ' ' << dir << '\n';
    go(x + dx[nd], y + dy[nd], nd);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 9) {
                for (int k = 0; k < 4; k++) {
                    go(i, j, k);
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[0][i][j] || ans[1][i][j] || ans[2][i][j] || ans[3][i][j]) {
                res++;
            }
        }
    }
    cout << res;
}