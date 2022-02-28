#include <stdio.h>
long long a[1000002] = { 0, };
int main() {
	long long min, max;
	scanf("%lld %lld", &min, &max);
	int count = 0;
	for (long long i = 2; i * i <= max; i++) {
		long long x = min / (i * i);
		if (min % (i * i) != 0)
			x++;
		while (x * (i * i) <= max) {
			a[x * (i * i) - min] = 1;
			x++;
		}
	}
	for (int i = 0; i <= max - min; i++) {
		if (a[i] == 0) {
			count++;
		}
	}
	printf("%d", count);
}