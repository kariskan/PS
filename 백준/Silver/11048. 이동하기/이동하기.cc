#include <stdio.h>

int a[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };

int max(int a, int b, int c) {
	if (a > b && a > c)return a;
	else if (b > a && b > c)return b;
	else return c;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	dp[1][1] = a[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == n && j == 1) dp[i][j] = dp[i - 1][j] + a[i][j];
			else if (i == 1) {
				if (j == 1)dp[i][j] = a[i][j];
				else dp[i][j] = dp[i][j - 1] + a[i][j];
			}
			else if (j == n && i == 1) dp[i][j] = dp[i][j - 1] + a[i][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + a[i][j];
		}
	}
	printf("%d", dp[n][m]);
}