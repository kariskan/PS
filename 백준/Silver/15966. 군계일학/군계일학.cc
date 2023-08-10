#include <iostream>
using namespace std;

int n, a[100001], dp[100001], vis[1000001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        vis[a[i]] = i;
        if (vis[a[i] - 1]) {
            dp[i] = dp[vis[a[i] - 1]] + 1;
        } else {
            dp[i] = 1;
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
