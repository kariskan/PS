#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
long long a[10000];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
	long long ans = 0;
	if (n % 2 != 0) {
		ans = a[n - 1];
		n--;
	}

	for (int i = 0; i < n / 2; i++) {
		ans = max(ans, a[i] + a[n - i - 1]);
	}

	cout << ans;
}