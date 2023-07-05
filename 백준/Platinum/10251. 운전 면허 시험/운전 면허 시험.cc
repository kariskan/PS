#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, l, g;
        cin >> n >> m >> l >> g;
        // {오른쪽으로 갈때 드는 연료, 밑으로 갈때 드는 연료}
        pair<int, int> board[101][101];

        // 마지막으로 l방향(0일때 오른쪽, 1일때 밑)으로 도착했고,
        // 방향을 k번 바꾸면서 {i,j}에 도달할 때
        // 드는 연료
        int dp[101][101][301][2] = {0};

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m - 1; j++) {
                cin >> board[i][j].first;
            }
        }
        for (int i = 1; i <= n - 1; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> board[i][j].second;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) {
                    continue;
                } else if (i == 1) {
                    dp[i][j][0][0] = dp[i][j - 1][0][0] + board[i][j - 1].first;
                } else if (j == 1) {
                    dp[i][j][0][1] = dp[i - 1][j][0][1] + board[i - 1][j].second;
                } else {
                    for (int k = 0; k <= 300; k++) {
                        if (dp[i - 1][j][k][1]) {
                            if (dp[i][j][k][1] == 0 || dp[i][j][k][1] > dp[i - 1][j][k][1] + board[i - 1][j].second) {
                                dp[i][j][k][1] = dp[i - 1][j][k][1] + board[i - 1][j].second;
                            }
                        }
                        if (dp[i - 1][j][k][0]) {
                            if (dp[i][j][k + 1][1] == 0 || dp[i][j][k + 1][1] > dp[i - 1][j][k][0] + board[i - 1][j].second) {
                                dp[i][j][k + 1][1] = dp[i - 1][j][k][0] + board[i - 1][j].second;
                            }
                        }
                        
                        if (dp[i][j - 1][k][1]) {
                            if (dp[i][j][k + 1][0] == 0 || dp[i][j][k + 1][0] > dp[i][j - 1][k][1] + board[i][j - 1].first) {
                                dp[i][j][k + 1][0] = dp[i][j - 1][k][1] + board[i][j - 1].first;
                            }
                        }
                        if (dp[i][j - 1][k][0]) {
                            if (dp[i][j][k][0] == 0 || dp[i][j][k][0] > dp[i][j - 1][k][0] + board[i][j - 1].first) {
                                dp[i][j][k][0] = dp[i][j - 1][k][0] + board[i][j - 1].first;
                            }
                        }
                    }
                }
            }
        }
        
        int ans = -1;
        for (int i = 0; i <= 300; i++){
            int mi;
            if (dp[n][m][i][0] == 0 && dp[n][m][i][1] == 0) {
                continue;
            } else if (dp[n][m][i][0] == 0){
                mi = dp[n][m][i][1];
            } else if (dp[n][m][i][1] == 0) {
                mi = dp[n][m][i][0];
            } else {
                mi = min(dp[n][m][i][0], dp[n][m][i][1]);
            }
            if (mi <= g) {
                ans = i;
                break;
            }
        }
        
        if (ans == -1) {
            cout << ans << '\n';
        } else {
            cout << l * (n + m - 2) + ans << '\n';
        }
    }
}