#include <iostream>
using namespace std;

int n, q, a[100002], sum[100002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] > a[i + 1]) sum[i]++;
		sum[i] += sum[i - 1];
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		int c, d; cin >> c >> d;
		cout << sum[d - 1] - sum[c - 1] << '\n';
	}
}