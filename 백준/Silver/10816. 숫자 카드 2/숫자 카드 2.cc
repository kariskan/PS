#include <iostream>
#include <algorithm>
using namespace std;
int a[500001] = { 0, };
int n, m;
int upper(int p) {
	int start = 0, end = n - 1;
	int ret = -1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (a[mid] <= p) {
			start = mid + 1;
			if (a[mid] == p)ret = mid;
		}
		else if (a[mid] > p) {
			end = mid - 1;
		}
	}
	return ret;
}
int lower(int p) {
	int start = 0, end = n - 1;
	int ret = -1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (a[mid] >= p) {
			end = mid - 1;
			if (a[mid] == p)ret = mid;
		}
		else if (a[mid] < p) {
			start = mid + 1;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		int ans1 = lower(p), ans2 = upper(p);
		if (ans1 == -1 && ans2 == -1)cout << 0 << " ";
		else cout << - ans1 + ans2 + 1 << " ";
	}
}