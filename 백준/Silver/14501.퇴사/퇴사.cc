#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int t[17] = { 0, }, p[17] = { 0, };
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}
	int dp[17] = { 0, }, pdp[17] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = i + t[i]; j <= n + 1; j++) {
			if (dp[j] < dp[i] + p[i])dp[j] = dp[i] + p[i];
		}
	}

	int max = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (max < dp[i])max = dp[i];
	}
	printf("%d", max);
}