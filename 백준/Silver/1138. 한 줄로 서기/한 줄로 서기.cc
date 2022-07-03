#include <iostream>
#include <algorithm>
using namespace std;
int a[11];
int n;
int ans[11];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ans[i] = i;
	}
	do {
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			int cnt = 0;
			for (int j = 1; j < i; j++) {
				if (ans[i] < ans[j])cnt++;
			}
			if (cnt != a[ans[i]]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			for (int i = 1; i <= n; i++) {
				cout << ans[i] << ' ';
			}
		}
	} while (next_permutation(ans + 1, ans + n + 1));
}