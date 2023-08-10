#include <iostream>
using namespace std;

int n;
char map[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool range(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= n; }

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    int hx, hy;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] == '*') {
                bool flag = true;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (!(range(nx, ny) && map[nx][ny] == '*')) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    cout << i << ' ' << j << '\n';
                    hx = i, hy = j;
                }
            }
        }
    }
    int tx = hx, ty = hy - 1, cnt = 0;
    while (ty >= 1 && map[hx][ty] == '*') {
        cnt++;
        ty--;
    }
    cout << cnt << ' ';
    ty = hy + 1, cnt = 0;
    while (ty <= n && map[hx][ty] == '*') {
        cnt++;
        ty++;
    }
    cout << cnt << ' ';
    tx = hx + 1, cnt = 0;
    while (tx <= n && map[tx][hy] == '*') {
        cnt++;
        tx++;
    }
    cout << cnt << ' ';
    int ex = tx;
    cnt = 0;
    while (range(tx, hy - 1) && map[tx][hy - 1] == '*') {
        cnt++;
        tx++;
    }
    cout << cnt << ' ';
    tx = ex, cnt = 0;
    while (range(tx, hy + 1) && map[tx][hy + 1] == '*') {
        cnt++;
        tx++;
    }
    cout << cnt;
}