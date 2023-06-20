#include <iostream>
using namespace std;

long long n, m, a[11][100001], dp[11][100001], ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1) {
                dp[j][i] = a[j][i];
            } else {
                for (int k = 1; k <= m; k++) {
                    if (k == j) {
                        dp[j][i] = max(dp[j][i], dp[k][i - 1] + a[j][i] / 2);
                    } else {
                        dp[j][i] = max(dp[j][i], dp[k][i - 1] + a[j][i]);
                    }
                }
            }
            if (i == n) {
                ans = max(ans, dp[j][i]);
            }
        }
    }

    cout << ans;
}