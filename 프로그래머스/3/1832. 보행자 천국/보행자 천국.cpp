#include <vector>
#include <iostream>
using namespace std;

int MOD = 20170805;

int solution(int n, int m, vector<vector<int>> city_map) {
    int dp[501][501][2]={0,};
    for(int i=1;i<=n;i++){
        if(city_map[i-1][0]==1){
            break;
        }
        dp[i][1][1]=1;
    }
    for(int i=1;i<=m;i++){
        if(city_map[0][i-1]==1){
            break;
        }
        dp[1][i][0]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(city_map[i-1][j-1]==1){
                continue;
            }
            dp[i][j][0]=(dp[i][j-1][0]+(city_map[i-1][j-2]==0?dp[i][j-1][1]:0))%MOD;
            dp[i][j][1]=((city_map[i-2][j-1]==0?dp[i-1][j][0]:0)+dp[i-1][j][1])%MOD;
        }
    }
    return (dp[n][m][0]+dp[n][m][1])%MOD;
}