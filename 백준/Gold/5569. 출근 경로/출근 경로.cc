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

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dp[101][101][2] = {0,};
    dp[1][1][0] = dp[1][1][1] = 1;

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            dp[i][j][0] = dp[i][j - 1][0] + dp[i - 1][j - 1][1];
            dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j - 1][0];
            dp[i][j][0] %= 100000;
            dp[i][j][1] %= 100000;
        }
    }
    cout << (dp[n][m][0] + dp[n][m][1]) % 100000;
}