#include <stdio.h>
int map[1000][1000] = { 0, };
int dp[1000][1000] = { 0, };
int min(int a, int b, int c) {
	if (a <= b && a <= c)return a;
	if (b <= a && b <= c)return b;
	return c;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			dp[i][j] = map[i][j];
			if (dp[i][j] == 1)ans = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0 && dp[i][j - 1] != 0 && dp[i - 1][j] != 0 && dp[i - 1][j - 1] != 0&&i>0&&j>0) {
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
				if (ans < dp[i][j])ans = dp[i][j];
			}
		}
	}
	printf("%d", ans * ans);
}