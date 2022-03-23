#include <iostream>
using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	long long ans = 0;
	long long x, y;
	long long c = min(n, m);
	c = (c - 1) / 2;
	n -= c * 2;
	m -= c * 2;
	x = 1 + c;
	y = 1 + c;
	ans += c * 4; 
	if (n == 1) {
		y += m - 1;
	}
	else if (m == 1) {
		ans++;
		x += n - 1;
	}
	else if (n == 2) {
		ans += 2;
		x++;
	}
	else {
		ans += 3;
		x++;
	}
	cout << ans << "\n" << x << " " << y;
}