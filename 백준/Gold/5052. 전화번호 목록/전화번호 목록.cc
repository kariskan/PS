#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
string a[10000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int f;
		for (int i = 0; i < n - 1; i++) {
			f = 0;
			for (int j = 0; j < a[i].length(); j++) {
				if (a[i][j] != a[i + 1][j]) {
					f = 1;
					break;
				}
			}
			if (f == 0) {
				break;
			}
		}
		if (!f)cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
}