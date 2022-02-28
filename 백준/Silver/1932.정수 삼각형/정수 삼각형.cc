#include <stdio.h>
#define max(a, b) a > b ? a : b
int a[501][501];
int main() {
	int n;
	int max1 = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &a[i][j]);
			if (j == 1)a[i][j] = a[i - 1][j] + a[i][j];
			else if (j == i)a[i][j] = a[i - 1][j - 1] + a[i][j];
			else {
				a[i][j] = max(a[i][j] + a[i - 1][j - 1], a[i][j] + a[i - 1][j]);
			}
			if (max1 < a[i][j])max1 = a[i][j];
		}
	}
	printf("%d", max1);

}