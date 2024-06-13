#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int a[1001][1001], dp[1001][1002][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (i == 1) {
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = a[i][j];
            }
        }
        dp[i][1][2] = dp[i][m][0] = INT_MAX;
    }
    int ans = INT_MAX;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j < m) {
                dp[i][j][0] = min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + a[i][j];
            }
            dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + a[i][j];
            if (j > 1) {
                dp[i][j][2] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + a[i][j];
            }
            if (i == n) {
                ans = min(ans, min(dp[i][j][0], min(dp[i][j][1], dp[i][j][2])));
            }
        }
    }
    cout << ans;
}