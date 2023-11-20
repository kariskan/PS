#include <iostream>
using namespace std;

int main() {
	int n, s, m;
	cin >> n >> s >> m;
	int a[51] = { 0, };
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int dp[51][1001] = { 0, };
	dp[0][s] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j - a[i] >= 0 && dp[i - 1][j - a[i]]) {
				dp[i][j] = 1;
			}
			if (j + a[i] <= m && dp[i - 1][j + a[i]]) {
				dp[i][j] = 1;
			}
		}
	}
	
	for (int i = m; i >= 0; i--) {
		if (dp[n][i]) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
}