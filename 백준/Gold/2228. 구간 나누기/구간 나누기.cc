#include <iostream>
using namespace std;

int n, m, a[100], sum[100], dp[100][100];

int go(int idx, int seq) {

	if (idx + 1 < 2 * seq - 1)return -987654321;
	if (seq <= 0)return 0;
	if (dp[idx][seq])return dp[idx][seq];
	int ret = -987654321;

	ret = max(ret, go(idx - 1, seq));
	for (int i = idx; i >= 0; i--) {
		ret = max(ret, go(i - 2, seq - 1) + sum[idx] - sum[i - 1]);
	}

	return dp[idx][seq] = ret;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0)sum[i] = a[i];
		else sum[i] = sum[i - 1] + a[i];
	}

	cout << go(n - 1, m);
	return 0;
}