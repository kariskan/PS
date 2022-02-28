#include <stdio.h>
int max(int a, int b, int c) {
	if (a > b) {
		if (a > c)return a;
		else return c;
	}
	else {
		if (b > c)return b;
		else return c;
	}
}
int a[10002] = { 0, };
int dp[10002];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dp[1] = a[1];
	dp[2] = dp[1] + a[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(a[i] + a[i - 1] + dp[i - 3], a[i] + dp[i - 2], dp[i - 1]);
	}
	printf("%d", dp[n]);
}