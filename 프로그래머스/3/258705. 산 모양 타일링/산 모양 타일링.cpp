#include <string>
#include <vector>

using namespace std;

long long dp[100000*2+2];
long long mod=10007;
int solution(int n, vector<int> tops) {
    int answer = 0;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n*2+1;i++){
        if(i%2==0){
            if(tops[(i-1)/2]){ //위 삼각형이 존재함
                dp[i]=dp[i-1]*2+dp[i-2];
            }else{
                dp[i]=dp[i-1]+dp[i-2];
            }
        }else{
            dp[i]=dp[i-1]+dp[i-2];
        }
        dp[i]%=mod;
    }
    return dp[2*n+1];
}