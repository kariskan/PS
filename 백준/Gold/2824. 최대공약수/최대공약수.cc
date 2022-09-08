#include <iostream>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long ar[1000], br[1000];

int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> br[i];
	}
	long long ans = 1, ok = 0;;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			long long gc = gcd(ar[i], br[j]);
			ans *= gc;
			ar[i] /= gc;
			br[j] /= gc;

			if (ans >= 1000000000) ok = 1;
			ans %= 1000000000;
		}
	}

	string res = to_string(ans);
	if (ok) {
		for (int i = 0; i < max(0, 9 - (int)res.length()); i++) {
			cout << 0;
		}
		for (int i = 0; i < res.length(); i++) {
			cout << res[i];
		}
	}
	else cout << res;
}