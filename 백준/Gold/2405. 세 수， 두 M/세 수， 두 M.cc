#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a>b?a:b
int a[100000];

int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2)
		return -1;

	if (num1 > num2)
		return 1;

	return 0;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	qsort(a, n, 4, compare);
	long long ans = 0;
	for (int i = 0; i < n - 2; i++) ans = max(ans, abs(a[n - 1] + a[i] - a[i + 1] * 2));
	for (int i = 1; i < n - 1; i++) ans = max(ans, abs(-a[0] + a[i] * 2 - a[i + 1]));



	printf("%lld", ans);

}