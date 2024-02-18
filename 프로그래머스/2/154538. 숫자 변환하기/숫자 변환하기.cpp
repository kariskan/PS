#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    int dp[1000001]={0,};
    dp[x]=1;
    for(int i=1;i<=y;i++){
        if(i-n>=1&&dp[i-n]&&(dp[i]==0||dp[i]>dp[i-n]+1)){
            dp[i]=dp[i-n]+1;
        }
        if(i%2==0&&i/2>=1&&dp[i/2]&&(dp[i]==0||dp[i]>dp[i/2]+1)){
            dp[i]=dp[i/2]+1;
        }
        if(i%3==0&&i/3>=1&&dp[i/3]&&(dp[i]==0||dp[i]>dp[i/3]+1)){
            dp[i]=dp[i/3]+1;
        }
    }
    return dp[y]==0?-1:dp[y]-1;
}