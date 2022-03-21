#include <iostream>
using namespace std;
pair<int, int> a[500];
int dp[500][500];
int run(int n, int m) {
	if (n == m) return 0;
	if (dp[n][m])return dp[n][m];

	int& ans = dp[n][m];
	for (int i = n; i < m; i++) {
		int k = run(n, i) + run(i + 1, m) + a[n].first * a[i].second * a[m].second;
		if (ans == 0 || ans > k)ans = k;
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	cout << run(0, n - 1);
}