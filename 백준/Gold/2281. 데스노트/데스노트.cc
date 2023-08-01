#include <iostream>
#include <cstring>
using namespace std;

int n, m, a[1001], sum[1001], dp[1001];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = (m - a[1]) * (m - a[1]);
    int ans = 2000000000;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (sum[i] - sum[j - 1] + i - j > m) {
                continue;
            }
            int c = dp[j - 1] + (m - (sum[i] - sum[j - 1] + i - j)) *
                                    (m - (sum[i] - sum[j - 1] + i - j));
            if (dp[i] == -1 || dp[i] > c) {
                dp[i] = c;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (sum[n] - sum[i] + n - i <= m) {
            ans = min(ans, dp[i]);
        }
    }
    cout << ans;
}