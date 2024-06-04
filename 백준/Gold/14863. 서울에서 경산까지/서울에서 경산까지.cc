#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

int a[101][4], dp[101][100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, ans = 0;
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
		for (int j = 0; j <= 100000; j++) {
			if (dp[i - 1][j] != -1 && j + a[i][0] <= k) {
				dp[i][j + a[i][0]] = max(dp[i][j + a[i][0]], dp[i - 1][j] + a[i][1]);
			}
			if (dp[i - 1][j] != -1 && j + a[i][2] <= k) {
				dp[i][j + a[i][2]] = max(dp[i][j + a[i][2]], dp[i - 1][j] + a[i][3]);
			}
			if (i == n) {
				ans = max(ans, dp[i][j]);
			}
		}
	}
	cout << ans;
}