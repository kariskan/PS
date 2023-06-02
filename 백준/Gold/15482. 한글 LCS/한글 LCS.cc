#include <iostream>
using namespace std;

string a, b;
int dp[1001][1001];

int main() {
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < a.length(); i += 3) {
        for (int j = 0; j < b.length(); j += 3) {
            if (i > 0) {
                dp[i / 3][j / 3] = max(dp[i / 3][j / 3], dp[i / 3 - 1][j / 3]);
            }
            if (j > 0) {
                dp[i / 3][j / 3] = max(dp[i / 3][j / 3], dp[i / 3][j / 3 - 1]);
            }
            if (a.substr(i, 3) == b.substr(j, 3)) {
                if (i == 0 || j == 0) {
                    dp[i / 3][j / 3] = max(dp[i / 3][j / 3], 1);
                } else {
                    dp[i / 3][j / 3] =
                        max(dp[i / 3][j / 3], dp[i / 3 - 1][j / 3 - 1] + 1);
                }
            }
            ans = max(ans, dp[i / 3][j / 3]);
        }
    }
    cout << ans;
}