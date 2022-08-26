#include <iostream>
using namespace std;

int n, a[100001], sum[100001], m;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = a[i] + sum[i - 1];
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;

		cout << sum[b] - sum[a - 1] << '\n';
	}
}