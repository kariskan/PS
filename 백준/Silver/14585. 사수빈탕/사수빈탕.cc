#include <iostream>
using namespace std;

long long n, m, a[301][301], dp[301][301];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        a[x][y] = max((long long)0, m - x - y);
    }
    long long ans = 0;
    for (int i = 0; i <= 300; i++) {
        for (int j = 0; j <= 300; j++) {
            if (i == 0 && j == 0) {
                continue;
            } else if (i == 0) {
                dp[i][j] = a[i][j] + dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] = a[i][j] + dp[i - 1][j];
            } else {
                dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}