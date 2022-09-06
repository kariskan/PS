#include <iostream>
using namespace std;

int a[4000004];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < q; i++) {
		int k; cin >> k;
		int c = k;
		bool ok = true;
		int t;
		while (k) {
			if (a[k]) {
				ok = false;
				t = k;
			}
			k /= 2;
		}
		if (ok) {
			a[c] = 1;
			cout << "0\n";
		}
		else cout << t << '\n';
	}
}