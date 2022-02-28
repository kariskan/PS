#include <stdio.h>

int main() {
	long long a[31] = { 0, };
	int b;
	scanf("%d", &b);
	if (b % 2 != 0)printf("0");
	else {
		a[0] = 1;
		a[2] = 3;

		long long sum = 0;
		for (int i = 4; i <= 30; i += 2) {
			sum = 0;
			for (int j = 0; j < i - 2; j += 2) {
				sum += a[j];
			}
			sum *= 2;
			a[i] = a[i - 2] * a[2] + sum;
		}
		printf("%lld", a[b]);
	}
}