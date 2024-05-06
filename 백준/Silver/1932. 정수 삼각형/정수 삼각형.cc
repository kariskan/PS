#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int a[501][501], dp[501][501];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	dp[1][1] = a[1][1];
	int answer = dp[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
			if (i == n) {
				answer = max(answer, dp[i][j]);
			}
		}
	}
	cout << answer;
}