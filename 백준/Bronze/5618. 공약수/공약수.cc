#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[3] = { 0, };
	int min = 100000001;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (min > a[i])min = a[i];
	}
	for (int i = 1; i <= min; i++)
		if (a[0] % i == 0 && a[1] % i == 0 && a[2] % i == 0)printf("%d\n", i);
}