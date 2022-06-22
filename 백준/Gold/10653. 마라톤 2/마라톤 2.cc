#include <iostream>
#include <cstring>
using namespace std;
pair<int, int> check[501];
int n, k;
int a[501][501], dp[501][501];
int go(int n, int k) {
	if (n == 1)return 0;
	if (dp[n][k] != -1)return dp[n][k];

	int m = 1000000000;

	for (int i = 0; i <= k; i++) {
		if(n - i - 1 >= 1) m = min(m, go(n - i - 1, k - i) + a[n - i - 1][n]);
	}
	return dp[n][k] = m;
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> check[i].first >> check[i].second;
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			a[i][j] = abs(check[i].first - check[j].first) + abs(check[i].second - check[j].second);
		}
	}
	cout << go(n, k);
	return 0;
}