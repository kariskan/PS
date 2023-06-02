#include <iostream>
using namespace std;

int r, c, k, map[1000][1000];
int dx[5] = {0,-1, 1, 0, 0};
int dy[5] = {0,0, 0, -1, 1};
int seq[4];

int nextDir(int dir) {
    for (int i = 0; i < 4; i++) {
        if (seq[i] == dir) {
            return seq[(i + 1) % 4];
        }
    }
}

int main() {
    cin >> r >> c >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }

    int sx, sy, dir;
    cin >> sx >> sy;
    for (int i = 0; i < 4; i++) {
        cin >> seq[i];
    }
    dir = seq[0];
    int cnt = 0;
    map[sx][sy] = 1;
    while (1) {
        int nx = sx + dx[dir];
        int ny = sy + dy[dir];

        if (nx >= 0 && nx < r && ny >= 0 && ny < c && !map[nx][ny]) {
            cnt = 0;
            sx = nx;
            sy = ny;
            map[sx][sy] = 1;
        } else {
            dir = nextDir(dir);
            cnt++;
        }
        if (cnt == 4) {
            break;
        }
    }

    cout << sx << ' ' << sy;
}