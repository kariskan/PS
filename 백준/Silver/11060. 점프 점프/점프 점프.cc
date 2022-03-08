#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[1000] = { 0, };
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int dp[1000] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= i + a[i] && j < n; j++) {
			if (dp[i] == 0)dp[j] = 1;
			else if (dp[j] > dp[i] + 1 && dp[j] != 0)dp[j] = dp[i] + 1;
			else if (dp[j] == 0) {
				dp[j] = dp[i] + 1;
			}

		}
	}
	int p = 0;
	for (int i = 1; i < n; i++)
		if (dp[i] == 0) {
			p = 1;
			break;
		}
	if (!p)
		printf("%d", dp[n - 1]);
	else printf("-1");
}