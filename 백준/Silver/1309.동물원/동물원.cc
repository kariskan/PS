#include <stdio.h>

long long dp[100001] = { 0, };
#define mod 9901
int main() {
	int n;
	scanf("%d", &n);
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] * 2 % mod + dp[i - 2] % mod) % mod;
	}
	printf("%lld", (dp[n]) % mod);
}