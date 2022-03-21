#include <iostream>
#include <vector>
using namespace std;

int dp[5001][5001] = { 0, };
int main() {
	int n;
	cin >> n;
	int v[5001] = { 0, }, v1[5001] = { 0, };
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		v1[n - i + 1] = v[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i] == v1[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << n - dp[n][n];
}