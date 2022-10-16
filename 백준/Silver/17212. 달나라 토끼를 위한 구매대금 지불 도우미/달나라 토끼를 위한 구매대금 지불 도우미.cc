#include <iostream>
using namespace std;

int dp[4][100001];
int a[4] = {1,2,5,7};

int main() {
    int n;cin>>n;
    
    for(int i=0;i<4;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = 987654321;
        }
    }
    
    for(int i=0;i<4;i++){
        for(int j=1;j<=n;j++){
            if(i==0) dp[i][j] = j;
            else {
                if(j < a[i]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = min(dp[i][j-a[i]]+1,dp[i-1][j]);
            }
        }
    }
    
    cout<<dp[3][n];
}
