#include <iostream>
using namespace std;

int n, m, a[301][301], dp[301][301];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            dp[i][j] = 2000000000;
        }
    }
    
    dp[1][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k < i; k++) {
                if (k + a[k][j] >= i) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + 1);
                }
            }
            for (int k = 1; k < j; k++) {
                if (k + a[i][k] >= j) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + 1);
                }
            }
        }
    }
    
    cout << dp[n][m];
}