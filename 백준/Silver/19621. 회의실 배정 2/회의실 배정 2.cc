#include <iostream>
using namespace std;

int n, dp[26];
pair<pair<int, int>, int> a[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    }
    dp[1] = a[1].second;

    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i].second);
    }
    
    cout << dp[n];
}