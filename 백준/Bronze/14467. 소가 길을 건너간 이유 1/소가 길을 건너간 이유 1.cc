#include <iostream>
using namespace std;

int n, a[11];

int main() {
	cin >> n;
	for (int i = 1; i <= 10; i++) {
		a[i] = -1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int b, c; cin >> b >> c;
		if (a[b] != -1 && a[b] != c) {
			ans++;
		}
		a[b] = c;
	}

	cout << ans;
}