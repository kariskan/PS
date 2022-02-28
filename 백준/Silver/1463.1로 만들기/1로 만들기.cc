#include <stdio.h>
#define min(x,y) x<y?x:y
int dp[1000001];
int main() {
	int x;
	scanf("%d", &x);
	dp[0] = dp[1] = 0;
	for (int i = 2; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)dp[i] = min(dp[i], dp[i/2] + 1);
		if (i % 3 == 0)dp[i] = min(dp[i], dp[i/3] + 1);
	}
	printf("%d", dp[x]);
}