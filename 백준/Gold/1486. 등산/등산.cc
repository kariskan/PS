#include <iostream>
using namespace std;

int n, m, t, d, map[25][25], map2[625][625];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int getDis(int now, int next) {
    if (now >= next) {
        return 1;
    } else {
        return abs(now - next) * abs(now - next);
    }
}

int main() {
    cin >> n >> m >> t >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            if (a >= 'A' && a <= 'Z') {
                map[i][j] = a - 'A';
            } else {
                map[i][j] = a - 'a' + 26;
            }
        }
    }
    for (int i = 0; i < n * m; i++) {
        for (int j = 0; j < n * m; j++) {
            map2[i][j] = 200000000;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (abs(map[i][j] - map[nx][ny]) <= t) {
                        map2[i * m + j][nx * m + ny] =
                            getDis(map[i][j], map[nx][ny]);
                    }
                }
            }
        }
    }

    for (int k = 0; k < n * m; k++) {
        for (int i = 0; i < n * m; i++) {
            for (int j = 0; j < n * m; j++) {
                map2[i][j] = min(map2[i][j], map2[i][k] + map2[k][j]);
            }
        }
    }
    int ans = map[0][0];
    for (int i = 1; i < n * m; i++) {
        if (map2[0][i] + map2[i][0] <= d) {
            ans = max(ans, map[i / m][i % m]);
        }
    }

    cout << ans;
}