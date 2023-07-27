#include <iostream>
#include <cstring>
using namespace std;

int dp[11][221][221], n, m, k;

int go(int len, int sum, int recent) {
    if (len > n || sum > m) {
        return 0;
    }
    if (dp[len][sum][recent] != -1) {
        return dp[len][sum][recent];
    }
    int res = 0;
    for (int i = recent; i <= m; i++) {
        res += go(len + 1, sum + i, i);
    }
    return dp[len][sum][recent] = res;
}

void go2(int len, int sum, int recent, int left) {
    if (len == n) {
        return;
    }
    
    for (int i = recent; i <= m; i++) {
        if (dp[len + 1][sum + i][i] == -1) {
            continue;
        }
        
        if (left > dp[len + 1][sum + i][i]) {
            left -= dp[len + 1][sum + i][i];
            continue;
        }
        
        cout << i << ' ';
        go2(len + 1, sum + i, i, left);
        break;
    }
}

int main() {
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        dp[n][m][i] = 1;
    }
    go(0, 0, 1);
    go2(0, 0, 1, k);
}