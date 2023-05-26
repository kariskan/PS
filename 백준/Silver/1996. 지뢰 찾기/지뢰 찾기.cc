#include <iostream>
using namespace std;

int map[1000][1000];
char ans[1000][1000];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char a;
            cin >> a;
            if (a == '.') {
                continue;
            } else {
                map[i][j] = a - '0';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] != 0) {
                ans[i][j] = '*';
            } else {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny]) {
                        cnt += map[nx][ny];
                    }
                }
                if (cnt >= 10) {
                    ans[i][j] = 'M';
                } else {
                    ans[i][j] = cnt + '0';
                }
            }
            cout << ans[i][j];
        }
        cout << '\n';
    }
}