#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int dp[10001][4] = {0,};

    dp[0][0] = 1;
    for (int i = 1; i <= 10000; i++) {
        dp[i][1] = 1;
        if (i >= 2) dp[i][2] = dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2];
        if (i >= 3) dp[i][3] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
    }
}
