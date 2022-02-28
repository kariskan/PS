#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	long long dp[92] = { 0, };
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%lld", dp[n]);
}