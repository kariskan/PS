#include <iostream>
using namespace std;

long long n, a[100001], sum[100001], m;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = a[i] + sum[i - 1];
	}

	long long ans = 0;

	for (int i = 1; i <= n; i++) {
		ans += a[i] * (sum[n] - sum[i]);
	}

	cout << ans;
}