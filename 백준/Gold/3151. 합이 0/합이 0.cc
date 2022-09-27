#include <iostream>
#include <algorithm>
using namespace std;

int a[10002];
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
	long long ans = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int k = -(a[i] + a[j]);
			int idx1 = lower_bound(a + j + 1, a + n, k) - a;
			int idx2 = upper_bound(a + j + 1, a + n, k) - a;
			ans += idx2 - idx1;
		}
	}

	cout << ans;
}