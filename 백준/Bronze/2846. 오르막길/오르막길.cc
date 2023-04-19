#include <iostream>
using namespace std;

int a[1001], dp[1001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] > a[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 1;
        }

        if (dp[i] >= 2 && ans < a[i] - a[i - dp[i] + 1]) {
            ans = a[i] - a[i - dp[i] + 1];
        }
    }

    cout << ans;
}