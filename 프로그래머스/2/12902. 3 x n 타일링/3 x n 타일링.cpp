#include <string>
#include <vector>

using namespace std;
long long dp[5001];
int solution(int n) {
    dp[0]=1;
    dp[2]=3;
    dp[4]=11;
    for(int i=6;i<=n;i+=2){
        dp[i]=(dp[i-2]*3)%1000000007;
        for(int j=0;j<i-2;j+=2){
            dp[i]=(dp[i]+dp[j]*2)%1000000007;
        }
    }
    return dp[n];
}