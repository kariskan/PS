#include <stdio.h>
int map[100000] = { 0, };
int dp[100000][2] = { 0, };
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &map[i]);
	}
	dp[0][0] = dp[0][1] = map[0];
	for (int i = 1; i < n; i++) {
		if (dp[i - 1][0] > 0)dp[i][0] = dp[i - 1][0] + map[i];
		else dp[i][0] = map[i];
		if (dp[i - 1][0] < dp[i - 1][1] + map[i])dp[i][1] = dp[i - 1][1] + map[i];
		else dp[i][1] = dp[i - 1][0];
	}
	int max = -1000000001;
	for (int i = 0; i < n; i++) {
		if (max < dp[i][0])max = dp[i][0];
		if (max < dp[i][1])max = dp[i][1];
	}
	printf("%d", max);
}