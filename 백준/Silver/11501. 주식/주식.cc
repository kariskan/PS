#include <iostream>
#include <cstring>
using namespace std;
int a[1000000], maxa[1000000];
int main() {
	cin.sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		maxa[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			maxa[i] = max(maxa[i + 1], a[i]);
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += maxa[i] - a[i];
		}
		cout << ans << '\n';
		memset(a, 0, sizeof(a));
		memset(maxa, 0, sizeof(maxa));
	}
}