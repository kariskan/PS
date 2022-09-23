#include <iostream>
using namespace std;
long long a[100001], s[200001];
int main() {
	long long n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n * 2; i++) {
		if (i > n) {
			s[i] += a[2 * n - i + 1] + s[i - 1];
		}
		else {
			s[i] += a[i] + s[i - 1];
		}

		if (k <= s[i]) {
			if (k == s[i]) {
				if (i <= n)continue;
				else cout << 2 * n - i + 1;
			}
			else {
				if (i > n) cout << 2 * n - i + 1;
				else cout << i;
			}
			break;
		}
	}
}