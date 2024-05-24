#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

long long n, a[5000];

// -97 -6 -2 6 98
// -24 -6 -3 -2 61 98 100
long long get(int l, int r, long long s) {
	if (r < 0 || r >= n || l < 0 || l >= n) {
		return (long long)2000000000 * 3;
	}

	long long mi = LLONG_MAX, k = LLONG_MAX;
	while (l <= r) {
		int mid = (l + r) / 2;

		if (mi > abs(s + a[mid])) {
			mi = abs(s + a[mid]);
			k = a[mid];
		}
		if (s + a[mid] < 0) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	vector<long long> ans = { 1000000000, 1000000000, 1000000000 };
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			long long l = get(0, i - 1, a[i] + a[j]);
			if (abs(ans[0] + ans[1] + ans[2]) >= abs(a[i] + a[j] + l)) {
				ans = { l,a[i],a[j] };
			}
			long long r = get(j + 1, n - 1, a[i] + a[j]);
			if (abs(ans[0] + ans[1] + ans[2]) >= abs(a[i] + a[j] + r)) {
				ans = { a[i],a[j],r };
			}
		}
	}
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}