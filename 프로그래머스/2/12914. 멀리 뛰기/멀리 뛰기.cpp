#include <string>
#include <vector>

using namespace std;
int dp[2001]={0,1,2};
long long solution(int n) {
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%1234567;
    }
    return dp[n];
}