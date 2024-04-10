class Solution {
    
    int dp[][] = new int[200][200];
    int matrix[][] = new int[200][200];
    public int solution(int[][] matrix) {
        int answer = 0;
        this.matrix=matrix;
        return go(0,matrix.length-1);
    }
    
    int go(int n,int m) {
        if (n>=m){
            return 0;
        }
        if (dp[n][m]>0){
            return dp[n][m];
        }
        int ret=Integer.MAX_VALUE;
        for(int i=n;i<m;i++){
            ret=Math.min(ret,go(n,i)+go(i+1,m)+matrix[n][0]*matrix[i][1]*matrix[m][1]);
        }
        return dp[n][m]=ret;
    }
}