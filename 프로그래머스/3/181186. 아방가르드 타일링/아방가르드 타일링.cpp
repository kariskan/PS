#include <string>
#include <vector>

using namespace std;
long long dp[100001]={1,1,3,10},mod=1000000007;
int solution(int n) {
    long long sum[3]={0,};
    for(int i=4;i<=n;i++){
        dp[i]+=dp[i-1]+dp[i-2]*2+dp[i-3]*5;
        sum[(i-4)%3]=(sum[(i-4)%3]+dp[i-4])%mod;
        dp[i]+=(sum[0]+sum[1]+sum[2]+sum[i%3])*2;
        dp[i]%=mod;
    }
    return dp[n];
}