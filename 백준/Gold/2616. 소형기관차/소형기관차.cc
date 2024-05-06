#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

// j번 소형 기관차가 i번째에 있는 객차까지 관리할 때, 최대 승객 수
int a[50001], sum[50001], dp[50001][3];
int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;

	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		if (i >= m) {
			dp[i][0] = sum[i] - sum[i - m];
		}
		dp[i][0] = max(dp[i][0], dp[i - 1][0]);
	}

	for (int i = 2 * m; i <= n - m; i++) {
		dp[i][1] = dp[i - m][0] + sum[i] - sum[i - m];
		dp[i][1] = max(dp[i][1], dp[i - 1][1]);
	}
	for (int i = 3 * m; i <= n; i++) {
		dp[i][2] = dp[i - m][1] + sum[i] - sum[i - m];
		dp[i][2] = max(dp[i][2], dp[i - 1][2]);
	}
	cout << dp[n][2];
	// 35 75 125 135 165 210 270

	//    75 90  60  30  45  60
	//    
}