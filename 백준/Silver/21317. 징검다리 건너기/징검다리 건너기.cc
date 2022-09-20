#include <iostream>
using namespace std;
int n, k, dp[30][2];
pair<int, int> a[30];
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i][1] = 1000000000;
	}
	cin >> k;
	dp[2][0] = a[1].first;
	dp[3][0] = min(a[1].second, a[1].first + a[2].first);
	for (int i = 4; i <= n; i++) {
		dp[i][0] = min(dp[i][0], min(dp[i - 1][0] + a[i - 1].first, dp[i - 2][0] + a[i - 2].second));
		dp[i][1] = min(dp[i][1], dp[i - 3][0] + k);
		dp[i][1] = min(dp[i][1], min(dp[i - 1][1] + a[i - 1].first, dp[i - 2][1] + a[i - 2].second));
	}
	cout << min(dp[n][0], dp[n][1]);
}