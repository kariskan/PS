#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int dp[1001];
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] % 10007 + dp[i - 2] % 10007) % 10007;
	}
	printf("%d", dp[n]);
}