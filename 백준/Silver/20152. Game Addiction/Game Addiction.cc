#include <iostream>
using namespace std;

long long dp[31][31];

int main(){
    int n,m;cin>>n>>m;
    if(n>m) swap(n,m);
    
    dp[n][n] = 1;
    
    for(int i=n;i<=m;i++){
        for(int j=n;j<=m;j++){
            if(j>i)continue;
            if(i-1>=0) {
                dp[i][j] += dp[i-1][j];
            }
            if(j-1>=0){
                dp[i][j] += dp[i][j-1];
            }
        }
    }
    
    cout<<dp[m][m];
}
