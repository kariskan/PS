#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <climits>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // n을 나타내는데 마지막 수가 j인 경우
    long long dp[100001][4] = {0,};

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for (int i = 4; i <= 100000; i++) {
        for (int j = 1; j <= 3; j++) {
            dp[i][j] += dp[i - j][1] + dp[i - j][2] + dp[i - j][3] - dp[i - j][j];
            dp[i][j] %= 1000000009;
        }
    }

    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        cout << (dp[a][1] + dp[a][2] + dp[a][3]) % 1000000009 << '\n';
    }
}