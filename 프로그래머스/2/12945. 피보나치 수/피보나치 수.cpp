#include <string>
#include <vector>

using namespace std;
int dp[100001]={0,1};
int solution(int n) {
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%1234567;
    }
    return dp[n];
}