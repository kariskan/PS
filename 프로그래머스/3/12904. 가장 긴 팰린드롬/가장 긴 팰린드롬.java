class Solution{
    
    int[][] dp = new int[2500][2500];
    String s;
    
    public int solution(String s){
        this.s = s;
        return go(0, s.length() - 1);
    }
    
    int go(int n, int m) {
        if (n > m) {
            return 0;
        }
        if (n == m) {
            return 1;
        }
        if (dp[n][m] > 0) {
            return dp[n][m];
        }
        int left = go(n, m - 1);
        int right = go(n + 1, m);
        int mid = go(n + 1, m - 1);
        if (s.charAt(n) == s.charAt(m) && mid == m - n - 1) {
            mid += 2;
        }
        return dp[n][m] = Math.max(left, Math.max(right, mid));
    }
}