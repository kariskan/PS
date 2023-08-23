#include <iostream>
using namespace std;

long long dp[1001][3][2], n;
long long mod = 1000000;

int main() {
    cin >> n;

    dp[1][0][0] = dp[1][0][1] = dp[1][1][0] = 1;
    // dp[i][j][k] == i일의 출결 정보에서
    // 결석을 j번 연속한 경우
    // 총 지각 개수가 k인 경우
    for (int i = 2; i <= n; i++) {
        dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][1][0] + dp[i - 1][2][0];
        dp[i][0][1] = dp[i - 1][0][1] + dp[i - 1][1][1] + dp[i - 1][2][1] +
                      dp[i - 1][0][0] + dp[i - 1][1][0] + dp[i - 1][2][0];

        dp[i][1][0] = dp[i - 1][0][0];
        dp[i][1][1] = dp[i - 1][0][1];

        dp[i][2][0] = dp[i - 1][1][0];
        dp[i][2][1] = dp[i - 1][1][1];
        
        dp[i][0][0] %= mod;
        dp[i][0][1] %= mod;
        dp[i][1][0] %= mod;
        dp[i][1][1] %= mod;
        dp[i][2][0] %= mod;
        dp[i][2][1] %= mod;
    }
    cout << (dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1] +
             dp[n][2][0] + dp[n][2][1]) %
                mod;
}