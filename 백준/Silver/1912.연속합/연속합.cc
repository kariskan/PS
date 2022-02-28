#include <stdio.h>
int a[100002];
int dp[100002];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dp[1] = a[1];
	for (int i = 2; i <= n; i++) {
		if (dp[i - 1] + a[i] > a[i])
			dp[i] = dp[i - 1] + a[i];
		else dp[i] = a[i];
	}
	int max = dp[1];
	for (int i = 1; i <= n; i++) {
		if (max < dp[i])max = dp[i];
	}
	printf("%d", max);

}