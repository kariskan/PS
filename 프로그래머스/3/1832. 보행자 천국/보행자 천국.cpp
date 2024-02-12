#include <vector>

using namespace std;

int MOD = 20170805;

int solution(int n, int m, vector<vector<int>> city_map) {
    int dp[501][501][2]={0,};
    dp[1][1][0]=dp[1][1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(city_map[i-1][j-1]==1||(i==1&&j==1)){
                continue;
            }
            if(i==1){
                dp[i][j][0]=dp[i][j-1][0];
                continue;
            }
            if(j==1){
                dp[i][j][1]=dp[i-1][j][1];
                continue;
            }
            
            if(city_map[i-1][j-2]==2){
                dp[i][j][0]=dp[i][j-1][0];
            }else{
                dp[i][j][0]=dp[i][j-1][0]+dp[i][j-1][1];
            }
            if(city_map[i-2][j-1]==2){
                dp[i][j][1]=dp[i-1][j][1];
            }else{
                dp[i][j][1]=dp[i-1][j][0]+dp[i-1][j][1];
            }
            dp[i][j][0]%=MOD;
            dp[i][j][1]%=MOD;
        }
    }
    return (dp[n][m][0]+dp[n][m][1])%MOD;
}