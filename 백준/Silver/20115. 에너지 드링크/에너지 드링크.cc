#include <iostream>
using namespace std;

int main() {
	long long n, m = 0;
	cin >> n;
	double ans = 0;
	for (int i = 0; i < n; i++) {
		long long a; cin >> a;
		ans += a;
		m = max(m, a);
	}

	cout << (ans - m) / 2 + m;
}