#include <string>
#include <vector>

using namespace std;

//dp[i][j] = (i,j)에 도달하기 위한 최소 시간
int dp[181][181];
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int maxAlp=0,maxCop=0;
    for(int i=0;i<=180;i++){
        for(int j=0;j<=180;j++){
            dp[i][j]=1e9;
        }
    }
    for(vector<int>p:problems){
        maxAlp=max(maxAlp,p[0]);
        maxCop=max(maxCop,p[1]);
    }
    alp=min(alp,maxAlp);
    cop=min(cop,maxCop);
    dp[alp][cop]=0;
    for(int i=alp;i<=maxAlp;i++){
        for(int j=cop;j<=maxCop;j++){
            if(i+1<=maxAlp){
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
            }
            if(j+1<=maxCop){
                dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
            }
            for(vector<int>p:problems){
                if(i>=p[0]&&j>=p[1]){
                    int nx=min(maxAlp,i+p[2]);
                    int ny=min(maxCop,j+p[3]);
                    dp[nx][ny]=min(dp[nx][ny],dp[i][j]+p[4]);
                }
            }
        }
    }

    return dp[maxAlp][maxCop];
}