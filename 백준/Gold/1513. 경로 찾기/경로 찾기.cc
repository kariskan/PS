#include <iostream>
using namespace std;

int n, m, c, a[51][51], dp[51][51][51][51];

int main() {
    cin >> n >> m >> c;
    dp[1][1][0][0] = 1;
    for (int i = 1; i <= c; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = i;
        if (x == 1 && y == 1) {
            dp[1][1][0][0] = 0;
            dp[1][1][i][1] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            if (a[i][j]) { // 오락실이 있는 경우
                for (int k = 0; k <= a[i][j] - 1; k++) {
                    for (int l = 0; l <= k; l++) {
                        dp[i][j][a[i][j]][l + 1] +=
                            (dp[i - 1][j][k][l] + dp[i][j - 1][k][l]) % 1000007;
                    }
                }
            } else { // 오락실이 없는 경우
                for (int k = 0; k <= c; k++) {
                    for (int l = 0; l <= k; l++) {
                        dp[i][j][k][l] +=
                            (dp[i - 1][j][k][l] + dp[i][j - 1][k][l]) % 1000007;
                    }
                }
            }
        }
    }

    for (int i = 0; i <= c; i++) {
        int sum = 0;
        for (int j = 0; j <= c; j++) {
            sum = (sum + dp[n][m][j][i]) % 1000007;
        }
        cout << sum << ' ';
    }
}