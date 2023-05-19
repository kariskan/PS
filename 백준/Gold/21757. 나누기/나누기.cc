#include <iostream>
using namespace std;

long long n, a[100001], sum[100001], dp[1001][5];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    if (sum[n] % 4 != 0) {
        cout << 0;
    } else if (sum[n] == 0) {
        int zeroCnt = 0;
        for (int i = 1; i <= n; i++) {
            if (sum[i] == 0) {
                zeroCnt++;
            }
        }
        cout << ((zeroCnt - 1) * (zeroCnt - 2) * (zeroCnt - 3)) / 6;
    } else {
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= 4; j++) {
            for (int i = 1; i <= n; i++) {
                dp[i][j] = dp[i - 1][j];
                if (sum[i] == (sum[n] / 4) * j) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        cout << dp[n][4];
    }
}