#include <stdio.h>
#include <math.h>
int num[300000] = { 0, };
int a[4000001] = { 0, };
int main() {
	for (int i = 2; i <= sqrt(4000000); i++) {
		if (a[i] != 0)continue;
		for (int j = i * 2; j <= 4000000; j += i) {
			a[j] = 1;
		}
	}
	int j = 0;
	for (int i = 2; i <= 4000000; i++)
		if (a[i] == 0) {
			num[j] = i;
			j++;
		}
	int sum = 0, ans = 0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= j; i++) {
		sum = 0;
		if (num[i] > n)break;
		for (int k = i; k <= j; k++) {
			sum += num[k];
			if (sum == n) {
				ans++;
				break;
			}
			else if (sum > n) {
				break;
			}
		}
	}
	printf("%d", ans);
}