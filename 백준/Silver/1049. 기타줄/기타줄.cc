#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a[50][2];
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a[i][0], &a[i][1]);
	}
	int minpackage = 10000;
	int min = 10000;
	for (int i = 0; i < m; i++) {
		if (minpackage > a[i][0])minpackage = a[i][0];
		if (min > a[i][1])min = a[i][1];
	}
	int ans = 0;
	if (minpackage > min * 6)ans = n * min;
	else {
		ans = minpackage * (n / 6);
		n = n % 6;
		if (minpackage < min * n)ans += minpackage;
		else ans += n * min;
	}
	printf("%d\n", ans);
}