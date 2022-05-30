#include <stdio.h>

int main() {
	int n; scanf("%d", &n);
	if (n == 1022) { printf("9876543210"); return 0; }
	else if (n > 1022) { printf("-1"); return 0; }
	long num = 0;
	int count = 0;
	while (1) {
		int p = 1;
		long temp = num;
		long jump = 1;
		long before = -1;
		while (temp) {
			if (temp % 10 <= before) {
				p = 0;
			}
			if (!p && temp % 10 > before) {
				break;
			}
			jump *= 10;
			before = temp % 10;
			temp /= 10;
		}
		if (p) {
			if (n == count++) {
				break;
			}
			num++;
		}
		else {
			jump /= 10;
			num += jump;
			num = num / jump * jump;
			continue;
		}
	}
	printf("%d", num);
}




















/*int is(long long n) {
	int a, b = -1;
	while (n) {
		a = n % 10;
		n /= 10;
		if (a <= b)return 1;
		b = a;
	}
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	if (n == 0) { printf("0"); return 0; }
	else if (n > 1022) { printf("-1"); return 0; }
	int a[10][10] = { 0, };
	for (int i = 1; i < 10; i++)
		a[0][i] = 1;
	for (int i = 1; i < 10; i++)
		for (int j = 1; j <= i; j++)
			a[1][i] += a[0][j];

	for (int i = 2; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < j; k++) {
				a[i][j] += a[i - 1][k];
			}
		}
	}
	int sum = 0;
	int b, p, bol = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (sum + a[i][j] >= n) {
				b = i, p = j;  bol = 1; break;
			}
			sum = sum + a[i][j];
		}
		if (bol == 1)break;
	}

	int k = n - sum - 1;
	long long temp = 0;
	long long ten = 1;
	for (int i = 0; i < b; i++) {
		temp = temp + i * ten;
		ten *= 10;
	}
	temp += p * ten;
	ten /= 10;
	long long ten1 = ten;
	
	for (int i = k; i; i--) {
		if (!ten1)ten1 = ten;
		temp += ten1;
		if (is(temp)) {
			while (is(temp)) {
				temp += ten1;
			}
		}
		ten1 /= 10;
	}
	for (int i = k; i; i--) {
		if (is(temp)) {
			i++;
			temp++;
		}
		else temp++;
	}
	printf("%lld", temp);
}*/