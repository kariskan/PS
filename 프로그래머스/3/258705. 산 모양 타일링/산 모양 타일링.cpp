#include <string>
#include <vector>

using namespace std;
int mod=10007, dp[200002];
int solution(int n, vector<int> tops) {
    dp[0]=1;
    dp[1]=(tops[0]==0?2:3);
    for(int i=2;i<2*n+1;i++){
        if(i%2==1&&tops[i/2]==1){
            dp[i]=dp[i-1]*2+dp[i-2];
        }else{
            dp[i]=dp[i-1]+dp[i-2];
        }
        dp[i]%=mod;
    }
    
    return dp[n*2];
}