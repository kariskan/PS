#include <string>
#include <vector>

using namespace std;
int map[101][101],dp[101][101];
int mod=1000000007;
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i=0;i<puddles.size();i++){
        map[puddles[i][1]][puddles[i][0]]=1;
    }
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1){
                continue;
            }
            if(map[i][j]){
                continue;
            }
            dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
        }
    }
    return dp[n][m];
}