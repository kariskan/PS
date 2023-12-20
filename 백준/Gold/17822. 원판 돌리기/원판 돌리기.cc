#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, t, map[50][50];

void rotate(int x, int d, int k) {
    int newMap[50];
    for (int i = 0; i < m; i++) {
        if (d == 0) {
            newMap[i] = map[x][(i - k + m) % m];
        } else {
            newMap[i] = map[x][(i + k) % m];
        }
    }
    for (int i = 0; i < m; i++) {
        map[x][i] = newMap[i];
    }
}

int main() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    while (t--) {
        int x, d, k;
        cin >> x >> d >> k;
        for (int i = x - 1; i < n; i += x) {
            rotate(i, d, k);
        }
        vector<pair<int, int>> v;
        int sum = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) {
                    continue;
                }
                sum += map[i][j];
                cnt++;
                if (map[i][j] == map[i][(j - 1 + m) % m]) {
                    v.push_back({i, j});
                    v.push_back({i, (j - 1 + m) % m});
                }
                if (map[i][j] == map[i][(j + 1) % m]) {
                    v.push_back({i, j});
                    v.push_back({i, (j + 1) % m});
                }
                if (i < n - 1 && map[i][j] == map[i + 1][j]) {
                    v.push_back({i, j});
                    v.push_back({i + 1, j});
                }
                if (i > 0 && map[i][j] == map[i - 1][j]) {
                    v.push_back({i, j});
                    v.push_back({i - 1, j});
                }
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if (!v.empty()) {
            while (!v.empty()) {
                map[v.back().first][v.back().second] = 0;
                v.pop_back();
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (map[i][j] == 0) {
                        continue;
                    }
                    if (sum % cnt == 0) {
                        if (sum / cnt > map[i][j]) {
                            map[i][j]++;
                        } else if (sum / cnt < map[i][j]) {
                            map[i][j]--;
                        }
                    } else {
                        if (sum / cnt >= map[i][j]) {
                            map[i][j]++;
                        } else {
                            map[i][j]--;
                        }
                    }
                }
            }
        }
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s += map[i][j];
        }
    }
    cout << s;
}