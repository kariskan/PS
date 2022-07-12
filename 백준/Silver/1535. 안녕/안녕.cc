#include <iostream>
using namespace std;

int n, h[21], g[21];
int dp[21][101];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> g[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 100; j++) {
			if (j + h[i] >= 100) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + h[i]] + g[i]);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}