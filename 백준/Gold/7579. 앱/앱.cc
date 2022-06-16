#include <iostream>
using namespace std;

int dp[101][10001]; //memory, cost
int a[101], c[101], sum;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		sum += c[i];
	}
	int ans = 1000000001;
	for (int i = 1; i <= n; i++) { //memory, cost
		for (int j = 0; j <= sum; j++) {
			if (j >= c[i]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + a[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	for (int i = 0; i <= sum; i++) {
		if (dp[n][i] >= m && ans > i) {
			ans = i;
			break;
		}
	}
	cout << ans;
}