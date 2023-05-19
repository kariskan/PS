#include <algorithm>
#include <iostream>
using namespace std;

int n, dp[101];
pair<int, int> a[101];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second) {
            swap(a[i].first, a[i].second);
        }
    }
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i].first >= a[j].first && a[i].second >= a[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans;
}