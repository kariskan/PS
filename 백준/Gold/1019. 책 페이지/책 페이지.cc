#include <stdio.h>
#include <math.h>
long long arr[10] = { 0, };

void calc(long long int n, long long int ten) {
	while (n) {
		arr[n % 10] += ten;
		n /= 10;
	}
}
void sol(long long int a, long long int b, long long int ten) {
	while (a % 10 != 0 && a <= b) {
		calc(a, ten);
		a++;
	}
	if (a > b)return;
	while (b % 10 != 9 && b >= a) {
		calc(b, ten);
		b--;
	}
	long long count = (b / 10 - a / 10 + 1);
	for (int i = 0; i < 10; i++) {
		arr[i] += count * ten;
	}
	sol(a / 10, b / 10, ten * 10);
}

int main() {
	int n;
	scanf("%d", &n);
	sol(1, n, 1);
	for (int i = 0; i < 10; i++) {
		printf("%lld ", arr[i]);
	}
}