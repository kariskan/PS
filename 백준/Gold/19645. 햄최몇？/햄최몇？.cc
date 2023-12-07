#include <iostream>
#include <algorithm>

using namespace std;

int a[50], n, dp[2501][2501]; // x, y 효용이 가능한 지

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= 0; j--) {
            for (int k = sum; k >= 0; k--) {
                if (j - a[i] >= 0) {
                    dp[j][k] = dp[j][k] || dp[j - a[i]][k];
                }
                if (k - a[i] >= 0) {
                    dp[j][k] = dp[j][k] || dp[j][k - a[i]];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= sum; i++) {
        for (int j = 0; j <= i; j++) {
            int me = sum - i - j;
            if (dp[i][j] && me <= i && me <= j) {
                ans = max(ans, me);
            }
        }
    }

    cout << ans;
}