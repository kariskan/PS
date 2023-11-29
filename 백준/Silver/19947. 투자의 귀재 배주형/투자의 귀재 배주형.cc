#include <iostream>

using namespace std;

int dp[11];

int main() {
    int h, y;
    cin >> h >> y;

    dp[0] = h;

    for (int i = 1; i <= y; i++) {
        dp[i] = dp[i - 1] * 1.05;
        if (i >= 3) {
            dp[i] = max(dp[i], (int) (dp[i - 3] * 1.2));
        }
        if (i >= 5) {
            dp[i] = max(dp[i], (int) (dp[i - 5] * 1.35));
        }
    }
    cout << dp[y];
}