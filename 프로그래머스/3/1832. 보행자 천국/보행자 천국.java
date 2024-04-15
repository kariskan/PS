class Solution {
    int MOD = 20170805;
    public int solution(int m, int n, int[][] cityMap) {
        int[][][] dp = new int[501][501][2];
        for (int i = 1; i <= n; i++) {
            if (cityMap[i - 1][0] == 1) {
                break;
            }
            dp[i][1][1] = 1;
        }
        for (int i = 1; i <= m; i++) {
            if (cityMap[0][i - 1] == 1) {
                break;
            }
            dp[1][i][0] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= m; j++) {
                if (cityMap[i - 1][j - 1] == 1) {
                    continue;
                }
                dp[i][j][0] = (dp[i][j - 1][0] + (cityMap[i - 1][j - 2] == 0 ? dp[i][j - 1][1] : 0)) % MOD;
                dp[i][j][1] = ((cityMap[i - 2][j - 1] == 0 ? dp[i - 1][j][0] : 0) + dp[i - 1][j][1]) % MOD;
            }
        }
        return (dp[n][m][0] + dp[n][m][1]) % MOD;
    }
}