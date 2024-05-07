#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, dp[101][100001];
pair<int, int> a[101];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j < a[i].first) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].first] + a[i].second);
		}
	}

	cout << dp[n][k];
}