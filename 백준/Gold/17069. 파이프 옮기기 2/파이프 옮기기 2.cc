#include <iostream>
using namespace std;

int n;
int map[33][33];
long long dp[3][33][33];
int main() {
	cin >> n;
	dp[0][1][2] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i == 1 ? 3 : 1; j <= n; j++) {
			if (!map[i][j])
				dp[0][i][j] = dp[0][i][j - 1] + dp[1][i][j - 1];
			if (!map[i][j] && !map[i - 1][j] && !map[i][j - 1])
				dp[1][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
			if (!map[i][j])
				dp[2][i][j] = dp[1][i - 1][j] + dp[2][i - 1][j];
		}
	}
	cout << dp[0][n][n] + dp[1][n][n] + dp[2][n][n];
}