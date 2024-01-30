#include <string>
#include <vector>

using namespace std;
int dp[101][101],map[101][101],mod=1000000007;
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(vector<int> p:puddles){
        map[p[1]][p[0]]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1){
                dp[i][j]=1;
                continue;
            }
            if(map[i][j]){
                continue;
            }
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    return dp[n][m];
}