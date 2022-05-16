#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if (num1 < num2)return -1;
	if (num1 > num2)return 1;
	return 0;
}
int a[200000] = { 0, };
int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, 4, compare);
	int start = 1;
	int end = a[n - 1] - a[0];
	int std, count = 0;
	int ans = (start + end) / 2;
	while (start <= end) {
		int mid = (start + end) / 2;
		std = a[0];
		count = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] - std >= mid) {
				count++;
				std = a[i];
			}
		}
		if (count >= c) {
			ans = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	printf("%d", ans);
}