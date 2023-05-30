#include <iostream>
using namespace std;

int n, m, map[500][500];

int main() {
    cin >> n >> m;
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            int cnt = 0;
            while (map[i][j]) {
                if (map[i][j] % 10 == 9) {
                    cnt++;
                }
                map[i][j] /= 10;
            }
            map[i][j] = cnt;
            total += map[i][j];
        }
    }
    int ans = total;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cnt += map[i][j];
        }
        ans = min(ans, total - cnt);
    }
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += map[j][i];
        }
        ans = min(ans, total - cnt);
    }
    cout << ans;
}