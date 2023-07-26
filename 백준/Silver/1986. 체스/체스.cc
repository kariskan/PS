#include <iostream>
using namespace std;

int n, m, map[1000][1000], q, k, p;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int kx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int ky[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main() {
    cin >> n >> m;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        map[a - 1][b - 1] = 1;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        map[a - 1][b - 1] = 2;
    }
    cin >> p;
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        map[a - 1][b - 1] = 3;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] <= 0) {
                continue;
            }
            if (map[i][j] == 1) {
                for (int kk = 0; kk < 8; kk++) {
                    int nx = i;
                    int ny = j;
                    while (1) {
                        nx += dx[kk];
                        ny += dy[kk];
                        if (map[nx][ny] > 0 || !(nx >= 0 && nx < n && ny >= 0 && ny < m)) {
                            break;
                        }
                        map[nx][ny] = -1;
                    }
                }
            } else if (map[i][j] == 2) {
                for (int kk = 0; kk < 8; kk++) {
                    int nx = i + kx[kk];
                    int ny = j + ky[kk];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] <= 0) {
                        map[nx][ny] = -1;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                ans++;
            }
        }
    }
    cout << ans;
}