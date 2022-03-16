#include <stdio.h>
#define dev 1000000000
long long a[1000001];
int main() {
	int n;
	scanf("%d", &n);
	if (n >= 0) {
		a[0] = 0;
		a[1] = 1;
		for (int i = 2; i <= n; i++) {
			a[i] = a[i - 2] % dev + a[i - 1] % dev;
		}
	}
	else {
		a[1] = 1;
		a[2] = -1;
		for (int i = 3; i <= -n; i++) {
			a[i] = a[i - 2] % dev - a[i - 1] % dev;
		}
	}
	if (n < 0)n = -n;
	if (a[n] > 0)printf("1\n");
	else if (a[n] == 0)printf("0\n");
	else printf("-1\n");
	if (a[n] < 0)a[n] = -1 * a[n];
	printf("%lld", a[n] % dev);
}