#include <string>
#include <vector>
#define mod 1000000007
using namespace std;
int dp[100001];
int solution(int n, vector<int> money) {
    int answer = 0;
    for (int i = 1; i <= money.size(); i++) {
        dp[0] = 1;
        for (int j = money[i - 1]; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - money[i - 1]]) % mod;
        }
    }
    return dp[n];
}
