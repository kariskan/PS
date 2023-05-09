#include <cstring>
#include <iostream>
using namespace std;

char map[5000][5000];
int cnt[11], cnt2[11];

void go(int n, int x, int y) {
    if (n == 1) {
        map[x][y] = '*';
        return;
    }
    if (n % 2 == 0) {
        for (int i = y; i < y + cnt[n]; i++) {
            map[x][i] = '*';
        }
        int t = 0;
        for (int i = x; i < x + cnt2[n]; i++) {
            map[i][y + t] = map[i][y + cnt[n] - 1 - t] = '*';
            t++;
        }
        go(n - 1, x + 1, y + (cnt[n]) / 4 + 1);
    } else {
        int t = 0;
        for (int i = x; i < x + cnt2[n]; i++) {
            map[i][cnt[n] / 2 + y + t] = map[i][cnt[n] / 2 + y - t] = '*';
            t++;
        }
        for (int i = y; i < y + cnt[n]; i++) {
            map[x + cnt2[n] - 1][i] = '*';
        }
        go(n - 1, x + +cnt2[n] / 2, y + (cnt[n]) / 4 + 1);
    }
}

int main() {
    memset(map, ' ', sizeof(map));
    int n;
    cin >> n;
    cnt[1] = cnt2[1] = 1;
    for (int i = 2; i <= 10; i++) {
        cnt[i] = cnt[i - 1] * 2 + 3;
        cnt2[i] = cnt2[i - 1] * 2 + 1;
    }

    go(n, 0, 0);
    for (int i = 0; i < cnt2[n]; i++) {
        int idx;
        for (int j = cnt[n] - 1; j >= 0; j--) {
            if (map[i][j] == '*') {
                idx = j;
                break;
            }
        }
        for (int j = 0; j <= idx; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
}