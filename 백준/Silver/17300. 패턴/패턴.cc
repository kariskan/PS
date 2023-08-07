#include <iostream>
using namespace std;

int map[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int n, a[9], vis[3][3];
int dx[16] = {-2, -2, -1, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 1, 2, 2};
int dy[16] = {-1, 1, -2, -1, 0, 1, 2, -1, 1, -2, -1, 0, 1, 2, -1, 1};

void go(int idx, int x, int y) {
    if (idx >= n) {
        cout << "YES";
        exit(0);
    }

    if (idx == 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (map[i][j] == a[0]) {
                    vis[i][j] = 1;
                    go(idx + 1, i, j);
                    return;
                }
            }
        }
    }

    for (int k = 0; k < 16; k++) {
        for (int len = 1; len <= 2; len++) {
            int nx = x + dx[k] * len;
            int ny = y + dy[k] * len;
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3 && !vis[nx][ny] &&
                map[nx][ny] == a[idx]) {
                if (map[nx][ny] == a[idx]) {
                    vis[nx][ny] = 1;
                    go(idx + 1, nx, ny);
                    return;
                }
            }
            if (len == 1 && !vis[nx][ny]) {
                break;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    go(0, 0, 0);
    cout << "NO";
}