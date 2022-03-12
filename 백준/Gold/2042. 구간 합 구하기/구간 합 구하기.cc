#include <iostream>
using namespace std;
long long tree[1000001] = { 0, };
long long seg[4000004] = { 0, };
long long init(int start, int end, int number) {
	if (start == end)return seg[number] = tree[start];
	int mid = (start + end) / 2;
	return seg[number] = init(start, mid, number * 2) + init(mid + 1, end, number * 2 + 1);
}
long long sum(int start, int end, int number, int left, int right) {
	if (left <= start && right >= end)return seg[number];
	if (end<left || start>right)return 0;
	int mid = (start + end) / 2;
	return sum(start, mid, number * 2, left, right) + sum(mid + 1, end, number * 2 + 1, left, right);
}
void update(int start, int end, int number, int index, long long value) {
	if (index<start || index>end)return;
	seg[number] += value;
	if (start == end)return;
	int mid = (start + end) / 2;
	update(start, mid, number * 2, index, value);
	update(mid + 1, end, number * 2 + 1, index, value);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> tree[i];
	}
	init(1, n, 1);
	for (int i = 0; i < m + k; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, b, c - tree[b]);
			tree[b] = c;
		}
		else {
			cout << sum(1, n, 1, b, c) << "\n";
		}
	}
}