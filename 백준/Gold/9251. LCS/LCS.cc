#include <stdio.h>
#include <string.h>
#define max(a, b) (a)<(b)?(b):(a)
char a[1002] = { 0, };
char b[1002] = { 0, };
int dp[1002][1002] = { 0, };
int i, j;
int main() {
	scanf("%s %s", a + 1, b + 1);
	for (i = 1; a[i]; i++) {
		for (j = 1; b[j]; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	printf("%d", dp[i - 1][j - 1]);
}