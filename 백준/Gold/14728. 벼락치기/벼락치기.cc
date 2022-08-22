#include <iostream>
using namespace std;

int n, t, dp[101][10001];
pair<int, int> a[101];

int main() {

	cin >> n >> t;

	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			if (j >= a[i].first && dp[i - 1][j - a[i].first] + a[i].second > dp[i][j]) {
				dp[i][j] = dp[i - 1][j - a[i].first] + a[i].second;
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	cout << dp[n][t];
}