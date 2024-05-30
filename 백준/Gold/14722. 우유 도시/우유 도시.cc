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

int board[1001][1001], dp[1001][1001][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                dp[i][j][0] = 1;
            }
        }
    }

    if (board[1][1] == 0) {
        dp[1][1][board[1][1]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            for (int k = 0; k < 3; k++) {
                if (board[i][j] != k) {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
                    continue;
                }
                if (dp[i - 1][j][(k + 2) % 3]) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][(k + 2) % 3] + 1);
                }
                if (dp[i][j - 1][(k + 2) % 3]) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][(k + 2) % 3] + 1);
                }
            }
        }
    }
    cout << max(dp[n][n][0], max(dp[n][n][1], dp[n][n][2]));
}