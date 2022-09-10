#include <iostream>
using namespace std;

int dp[100001];
pair<int, int> inp[20];

int main() {
	int c, n;
	cin >> c >> n;
	int m = 0;
	for (int i = 0; i < n; i++) {
		cin >> inp[i].first >> inp[i].second;
		m = max(m, inp[i].second);
	}
	for (int i = 1; i <= c + m; i++) {
		dp[i] = 987654321;
	}

	for (int i = 1; i <= c + m; i++) {
		for (int j = 0; j < n; j++) {
			if (i % inp[j].second == 0) {
				dp[i] = min(dp[i], (i / inp[j].second) * inp[j].first);
			}
			if (i - inp[j].second > 0) {
				dp[i] = min(dp[i], dp[i - inp[j].second] + inp[j].first);
			}
		}
	}
	int ans = 987654321;
	for (int i = c; i <= c + m; i++) {
		ans = min(ans, dp[i]);
	}

	cout << ans;
}