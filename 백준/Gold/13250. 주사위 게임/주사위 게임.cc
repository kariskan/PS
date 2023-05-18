#include <iostream>
using namespace std;

double dp[1000001];
int n;

int main() {
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
            }

            dp[i] += 1;
        }
        dp[i] /= 6;
    }

    cout << fixed;
    cout.precision(10);
    cout << dp[n];
}