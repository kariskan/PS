#include <iostream>
using namespace std;
#define mod 1000000007
long long tree[1000001] = { 0, };
long long seg[4000004] = { 0, };

long long init(int start, int end, int number) {
	if (start == end)return seg[number] = tree[start];
	int mid = (start + end) / 2;
	return seg[number] = ((init(start, mid, number * 2) % mod) * (init(mid + 1, end, number * 2 + 1) % mod)) % mod;
}

long long sum(int start, int end, int number, int left, int right) {
	if (end<left || start>right) return 1;
	if (left <= start && right >= end)return seg[number];
	int mid = (start + end) / 2;
	long long m1 = sum(start, mid, number * 2, left, right) % mod;
	long long m2 = sum(mid + 1, end, number * 2 + 1, left, right) % mod;
	return (m1 * m2) % mod;
}

long long modify(int start, int end, int number, int index, long long value) {
	if (index<start || index>end)return seg[number];
	if (start == end) return seg[number] = value;
	int mid = (start + end) / 2;
	long long m1 = modify(start, mid, number * 2, index, value);
	long long m2 = modify(mid + 1, end, number * 2 + 1, index, value);
	return seg[number] = (m1 * m2) % mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> tree[i];
	}
	init(1, n, 1);
	for (int i = 0; i < m + k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			modify(1, n, 1, b, c);
		}
		else {
			cout << sum(1, n, 1, b, c) % mod << "\n";
		}
	}
}