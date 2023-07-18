#include <iostream>
using namespace std;

int n, m, mod = 1000000007, dp[10001];

int main() {
    cin >> n >> m;
    dp[0] = 1;
    for (int i = 1; i < m; i++) {
        dp[i] = 1;
    }
    for (int i = m; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - m]) % mod;
    }
    cout << dp[n];
}