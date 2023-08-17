#include <iostream>
using namespace std;

int n, dp[(1 << 15) + 1][5];

int main() {
    for (int i = 1; i * i <= (1 << 15); i++) {
        dp[i * i][1] = 1;
        for (int j = i * i; j <= (1 << 15); j++) {
            dp[j][2] += dp[j - i * i][1];
            dp[j][3] += dp[j - i * i][2];
            dp[j][4] += dp[j - i * i][3];
        }
    }
    
    while (1) {
        cin >> n;
        if (n == 0) {
            break;
        }
        cout << dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] << '\n';
    }
}