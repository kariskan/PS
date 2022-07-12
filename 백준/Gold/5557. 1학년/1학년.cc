#include <iostream>
using namespace std;
long long a[101], dp[101][21];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1][a[1]] = 1;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < 21; j++) {
			if (dp[i - 1][j]) {
				if (j + a[i] <= 20) {
					dp[i][j + a[i]] += dp[i - 1][j];
				}
				if (j - a[i] >= 0) {
					dp[i][j - a[i]] += dp[i - 1][j];
				}
			}
		}
	}
	cout << dp[n - 1][a[n]];
}