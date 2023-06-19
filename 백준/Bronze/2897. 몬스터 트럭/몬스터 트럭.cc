#include <iostream>
using namespace std;

int ans[5];
char map[50][50];

int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (map[i][j] == '#' || map[i][j + 1] == '#' ||
                map[i + 1][j] == '#' || map[i + 1][j + 1] == '#') {
                continue;
            }
            int cnt = 0;
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    if (map[i + k][j + l] == 'X') {
                        cnt++;
                    }
                }
            }
            ans[cnt]++;
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << ans[i] << '\n';
    }
}