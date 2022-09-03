#include <iostream>
using namespace std;

int dp[101][101][2];

int go(int i, int j, int k) {

	if (dp[i][j][k])return dp[i][j][k];
	if (i < 0 || j < 0 || i <= j)return 0;
	if (i == j + 1) {
		if (k == 0)return 0;
		else return 1;
	}

	int ret = 0;
	if (k == 1) {
		ret = go(i - 1, j, 0) + go(i - 1, j - 1, 1);
	}
	else {
		ret = go(i - 1, j, 1) + go(i - 1, j, 0);
	}

	return dp[i][j][k] = ret;
}

int main() {
	int n;
	cin >> n;

	dp[1][0][0] = 1;
	dp[1][0][1] = 1;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		cout << go(a, b, 0) + go(a, b, 1) << '\n';
	}
}