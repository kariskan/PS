#include <stdio.h>
int dp[201][201] = { 0, };
#define mod 1000000000
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		dp[i][1] = 1;
		for (int j = 1; j <= m; j++) {
			if (i == 1)dp[i][j] = j;
			else
				dp[i][j] = (dp[i - 1][j] % mod + dp[i][j - 1] % mod) % mod;
		}
	}
	printf("%d\n", dp[n][m] % mod);
}