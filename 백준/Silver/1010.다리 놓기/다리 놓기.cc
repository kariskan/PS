#include <stdio.h>
long long a[30][30] = { 0, };

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i <= m; i++){
			a[1][i] = i;
	}
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= m; j++) {
				for (int k = j; k >= i; k--) {
					a[i][j] += a[i - 1][k - 1];
				}
			}
		}
		printf("%lld\n", a[n][m]);
		for (int i = 0; i < 30; i++)
			for (int j = 0; j < 30; j++)
				a[i][j] = 0;
	}

}