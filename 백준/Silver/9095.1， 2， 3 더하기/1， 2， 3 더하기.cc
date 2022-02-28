#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	int dp[11];
	dp[1] = 1; dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
}