class Solution {
    
    int[][] pos={{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
    int[][][] dp = new int[100000][10][10];
    String numbers;
    
    public int solution(String numbers) {
        this.numbers = numbers;
        return go(0, 4, 6);
    }
    
    int go(int n, int left, int right) {
        if (n >= numbers.length()) {
            return 0;
        }
        if (dp[n][left][right] > 0) {
            return dp[n][left][right];
        }
        int num = numbers.charAt(n) - '0';
        if (num == left || num == right) {
            return dp[n][left][right] = go(n + 1, left, right) + 1;
        }
        int l = go(n + 1, num, right) + getDistance(left, num);
        int r = go(n + 1, left, num) + getDistance(right, num);
        return dp[n][left][right] = Math.min(l, r);
    }
    
    int getDistance(int s, int d) {
        if (s == d) {
            return 1;
        }
        int min = Math.min(Math.abs(pos[s][0]-pos[d][0]),
                           Math.abs(pos[s][1]-pos[d][1]));
        
        int max = Math.max(Math.abs(pos[s][0]-pos[d][0]),
                           Math.abs(pos[s][1]-pos[d][1]));
        return 3 * min + 2 * (max - min);
    }
}