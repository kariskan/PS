#include <iostream>
using namespace std;

int a[100001], dp[100001], n, m;

int main() {
    cin >> n >> m;

    int ans = 0, mindp = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = dp[i - 1] + a[i];

        if (i >= m) {
            mindp = min(mindp, dp[i - m]);
            ans = max(ans, dp[i] - mindp);
        }
    }
    cout << ans;
}
