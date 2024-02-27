#include <string>
#include <vector>

using namespace std;

long long dp[5001][2],mod=1000000007;
int solution(int n) {    
    dp[0][0]=1;
    dp[2][0]=3;
    dp[2][1]=2;
    for(int i=4;i<=n;i+=2){
        dp[i][1]=(dp[i-2][0]*2+dp[i-2][1])%mod;
        dp[i][0]=(dp[i-2][0]*3+dp[i-2][1])%mod;
    }
    return dp[n][0];
}