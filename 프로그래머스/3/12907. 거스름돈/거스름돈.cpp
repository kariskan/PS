#include <string>
#include <vector>

using namespace std;
int dp[100001];

int solution(int n, vector<int> money) {
    dp[0]=1;
    for(int i=0;i<money.size();i++){
        for(int j=1;j<=n;j++){
            if(j<money[i]){
                continue;
            }
            dp[j]=(dp[j]+dp[j-money[i]])%1000000007;
        }
    }
    return dp[n];
}