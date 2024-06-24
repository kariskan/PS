#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dp[201][201] = {0,};

    int n, m;
    cin >> n >> m;
    dp[0][0] = 1;
    for (int i = 0; i <= 200; i++) {
        for (int j = 1; j <= 200; j++) {
            for (int k = 0; k <= 200; k++) {
                if (i - k >= 0) {
                    dp[i][j] += dp[i - k][j - 1];
                    dp[i][j] %= 1000000000;
                }
            }
        }
    }

    cout << dp[n][m];
}