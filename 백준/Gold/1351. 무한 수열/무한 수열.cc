#include <stdio.h>
int dp[10000001]={0,};
long long sol(long long N, long long P, long long Q){
    
    if(N<=10000000)return dp[N];
    return sol(N/P, P, Q) + sol(N/Q, P, Q);
    }

int main(){
    long long N,P,Q;
    scanf("%lld %lld %lld", &N,&P,&Q);
    dp[0]=1;
    for(int i=1;i<=10000000;i++){
        dp[i]=dp[i/P]+dp[i/Q];
        }
    printf("%lld", sol(N,P,Q));
    }
    