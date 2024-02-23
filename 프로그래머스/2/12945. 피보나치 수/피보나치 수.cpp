#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int dp[100001]={0,1,};
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%1234567;
    }
    return dp[n];
}