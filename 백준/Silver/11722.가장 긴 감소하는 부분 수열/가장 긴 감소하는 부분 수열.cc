#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[1001] = { 0, };
	int dp[1001] = { 0, };
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] > a[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++)
		if (max < dp[i])max = dp[i];
	printf("%d", max);
}