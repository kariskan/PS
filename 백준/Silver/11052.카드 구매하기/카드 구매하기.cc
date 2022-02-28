#include <stdio.h>
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int p[1001] = { 0, };
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	int dp[1001] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + p[j]);
		}
	}
	printf("%d", dp[n]);
}