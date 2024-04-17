class Solution {
    
    int[][] dp = new int[100001][2];
    
    public int[] solution(int target) {
        for (int i = 1; i <= target; i++) {
            dp[i][0] = dp[i][1] = Integer.MAX_VALUE;
        }
        for (int i = 0; i < target; i++) {
            for (int j = 1; j <= 20; j++) {
                for (int k = 1; k <= 3; k++) {
                    int nx = i + j * k;
                    if (nx > target) {
                        continue;
                    }
                    int[] nd = {dp[i][0] + 1, dp[i][1]};
                    if (k == 1) {
                        nd[1]++;
                    }
                    if (dp[nx][0] > nd[0] || (dp[nx][0] == nd[0] && dp[nx][1] < nd[1])) {
                        dp[nx] = new int[]{nd[0], nd[1]};
                    }
                }
            }
            if (i + 50 <= target) {
                if (dp[i + 50][0] > dp[i][0] + 1 || (dp[i + 50][0] == dp[i][0] + 1 && dp[i + 50][1] < dp[i][1] + 1)) {
                    dp[i + 50] = new int[]{dp[i][0] + 1, dp[i][1] + 1};
                }
            }
        }
        return new int[]{dp[target][0], dp[target][1]};
    }
}