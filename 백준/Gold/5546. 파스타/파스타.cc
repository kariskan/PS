#include <iostream>
using namespace std;

int a[101], dp[101][4][4], n, c;

int main() {
    cin >> n >> c;
    for (int i = 1; i <= c; i++) {
        int d, b;
        cin >> d >> b;
        a[d] = b;
    }

    if (a[1]) {
        dp[a[1]][a[1]][a[1]] = 1;
    } else {
        dp[1][1][1] = dp[1][2][2] = dp[1][3][3] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {  // i
            if (a[i] == 0 || a[i] == j) {
                for (int k = 1; k <= 3; k++) {      // i-1
                    for (int l = 1; l <= 3; l++) {  // i-2
                        if (i >= 3 && j == k && k == l) {
                            continue;
                        }
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][k][l]) % 10000;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            ans = (ans + dp[n][i][j]) % 10000;
        }
    }
    cout << ans;
}