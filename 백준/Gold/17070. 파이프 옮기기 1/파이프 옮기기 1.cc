#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int board[18][18] = {0,}, dp[18][18][3] = {0,};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    dp[0][1][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j][0]) {
                if (!board[i][j + 1]) {
                    dp[i][j + 1][0] += dp[i][j][0];
                    if (!board[i + 1][j] && !board[i + 1][j + 1]) {
                        dp[i + 1][j + 1][2] += dp[i][j][0];
                    }
                }
            }
            if (dp[i][j][1]) {
                if (!board[i + 1][j]) {
                    dp[i + 1][j][1] += dp[i][j][1];
                    if (!board[i][j + 1] && !board[i + 1][j + 1]) {
                        dp[i + 1][j + 1][2] += dp[i][j][1];
                    }
                }
            }
            if (dp[i][j][2]) {
                if (!board[i][j + 1]) {
                    dp[i][j + 1][0] += dp[i][j][2];
                }
                if (!board[i + 1][j]) {
                    dp[i + 1][j][1] += dp[i][j][2];
                }
                if (!board[i + 1][j] && !board[i][j + 1] && !board[i + 1][j + 1]) {
                    dp[i + 1][j + 1][2] += dp[i][j][2];
                }
            }
        }
    }

    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
}
