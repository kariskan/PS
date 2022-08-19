#include <iostream>
using namespace std;

int n, m, a[50001], sum[50001], dp[4][50001];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}

	cin >> m;

	for (int i = 1; i <= 3; i++) {
		for (int j = i * m; j <= n - (3 - i) * m; j++) {
			dp[i][j] = max(dp[i][j - 1], sum[j] - sum[j - m] + dp[i - 1][j - m]);
		}
	}

	cout << dp[3][n];
}