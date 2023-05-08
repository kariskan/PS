#include <cstring>
#include <iostream>
using namespace std;

char ans[1000][1000];

void go(int n, int m, int a) {
    if (a == 1) {
        ans[n][m] = ans[n][m + 1] = ans[n][m + 2] = ans[n + 1][m] = ans[n + 2][m] = '*';
        return;
    }
    for (int i = m; i < m + 4 * a - 3; i++) {
        ans[n][i] = '*';
        ans[n + 4 * a - 2][i] = '*';
    }
    for (int i = n + 1; i < n + 4 * a - 1; i++) {
        ans[i][m] = '*';
        ans[i][m + 4 * a - 4] = '*';
    }
    ans[n + 1][m + 4 * a - 4] = ' ';
    ans[n + 2][m + 4 * a - 5] = '*';
    go(n + 2, m + 2, a - 1);
}

int main() {
    int a;
    cin >> a;
    memset(ans, ' ', sizeof(ans));
    if (a == 1) {
        cout << "*";
    } else {
        go(0, 0, a);
        for (int i = 0; i < 4 * a - 1; i++) {
            for (int j = 0; j < 4 * a - 3; j++) {
                cout << ans[i][j];
                if (i == 1) {
                    break;
                }
            }
            cout << '\n';
        }
    }
}