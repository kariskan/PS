#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[1000] = { 0, };
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int dp[1000] = { 0, };
	for (int i = 0; i < n; i++) {
		dp[i] = a[i];
	}

	for (int i = 0; i <n; i++) {
		for (int j = 0; j <= i; j++)
			if (a[j] < a[i] && dp[i] < dp[j] + a[i])
				dp[i] = dp[j] + a[i];
	}


	int max = 0;
	for (int i = 0; i < n; i++)
		if (max < dp[i])max = dp[i];
	printf("%d", max);
}