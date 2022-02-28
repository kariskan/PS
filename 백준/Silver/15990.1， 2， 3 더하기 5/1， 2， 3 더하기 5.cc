#include <iostream>
using namespace std;
long long dp[100001][4] = { 0, };
#define m 1000000009

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		for (int j = 1; j < 4; j++) {
			if (j == 1) {
				dp[i][j] = (dp[i - 1][2] % m + dp[i - 1][3] % m) % m;
			}
			else if (j == 2) {
				dp[i][j] = (dp[i - 2][1] % m + dp[i - 2][3] % m) % m;
			}
			else {
				dp[i][j] = (dp[i - 3][1] % m + dp[i - 3][2] % m) % m;
			}
		}
	}

	while (t--) {
		int n;
		cin >> n;
		cout << (dp[n][1] % m + dp[n][2] % m + dp[n][3] % m) % m << "\n";
	}
}