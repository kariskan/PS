#include <cmath>
#include <iostream>
using namespace std;

int n, maxCnt;
char ans[8][101];

void go(int l, int r, int cnt) {
    if (cnt > (int)log2(n)) {
        return;
    }
    if (l >= r) {
        if (l == r) {
            if (l % 2 == 1) {
                ans[cnt][l] = 'A';
            } else {
                ans[cnt][l] = 'B';
            }
        }
        return;
    }

    maxCnt = max(maxCnt, cnt);
    for (int i = l; i <= r; i++) {
        if (i <= (l + r) / 2) {
            ans[cnt][i] = 'A';
        } else {
            ans[cnt][i] = 'B';
        }
    }

    go(l, (l + r) / 2, cnt + 1);
    go((l + r) / 2 + 1, r, cnt + 1);
}

int main() {
    cin >> n;
    go(1, n, 0);

    for (int i = 0; i <= maxCnt; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    for (int i = 1; i < 7 - maxCnt; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1)
                cout << "A";
            else
                cout << "B";
        }
        cout << "\n";
    }
}