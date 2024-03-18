#include <string>
#include <vector>

using namespace std;

int dp[152][152], n=150;
int solution(int alp, int cop, vector<vector<int>> problems) {
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=1e9;
        }
    }
    
    int maxAlp=0,maxCop=0;
    for(vector<int> p:problems){
        maxAlp=max(maxAlp,p[0]);
        maxCop=max(maxCop,p[1]);
    }
    alp=min(alp,maxAlp);
    cop=min(cop,maxCop);
    dp[alp][cop]=0;
    
    for(int i=alp;i<=maxAlp;i++){
        for(int j=cop;j<=maxCop;j++){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
            for(vector<int> p:problems){
                if(i<p[0]||j<p[1]){
                    continue;
                }
                int x=min(maxAlp,i+p[2]);
                int y=min(maxCop,j+p[3]);
                dp[x][y]=min(dp[x][y],dp[i][j]+p[4]);
            }
        }
    }
    return dp[maxAlp][maxCop];
}