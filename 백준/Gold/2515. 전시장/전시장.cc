#include <algorithm>
#include <iostream>
using namespace std;

int n, s;
pair<int, int> a[300001], dp[300001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a + 1, a + 1 + n);
    dp[1].first = a[1].second;
    dp[1].second = 1;
    for (int i = 2; i <= n; i++) {
        int left = 0, right = i - 1;
        int p = 0;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (a[i].first - a[dp[mid].second].first >= s) {
                p = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        dp[i].first = dp[p].first + a[i].second;
        dp[i].second = i;

        if (dp[i].first < dp[i - 1].first) {
            dp[i].first = dp[i - 1].first;
            dp[i].second = dp[i - 1].second;
        }
    }

    cout << dp[n].first;
}