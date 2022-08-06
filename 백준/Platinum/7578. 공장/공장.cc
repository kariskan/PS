#include <stdio.h>
int a[500001] = { 0, };
int b[500001] = { 0, };
int index[1000001] = { 0, };
long long segmenttree[2000004] = { 0, };

long long sum(int start, int end, int number, int left, int right) {
	if (right<start || left>end)return 0;
	if (start >= left && end <= right)return segmenttree[number];
	int mid = (start + end) / 2;
	return sum(start, mid, number * 2, left, right) + sum(mid + 1, end, number * 2 + 1, left, right);
}
void update(int start, int end, int number, int in, int dif) {
	if (in<start || in>end)return;
	segmenttree[number] += dif;
	if (start == end)return;
	int mid = (start + end) / 2;
	update(start, mid, number * 2, in, dif);
	update(mid + 1, end, number * 2 + 1, in, dif);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		index[b[i]] = i;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += sum(1, n, 1, index[a[i]] + 1, n);
		update(1, n, 1, index[a[i]], 1);
	}
	printf("%lld", ans);
}