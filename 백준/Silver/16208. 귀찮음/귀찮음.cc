#include <iostream>
#include <algorithm>
using namespace std;

int a[500000];
long long ans, sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		ans += (sum - a[i]) * a[i];
		sum -= a[i];
	}

	cout << ans;
}