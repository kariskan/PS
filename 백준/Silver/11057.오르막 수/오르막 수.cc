#include <stdio.h>
#define mod 10007
int dp[1000][10] = { 0, };
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 10; i++)
		dp[0][i] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k] % mod;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum += dp[n - 1][i] % mod;
	printf("%d", sum % mod);
}