#include <iostream>
#include <climits>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	long long n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	long long ans = 0;

	if (a * d < b * c) {
		swap(a, c);
		swap(b, d);
	}

	long long lcm = (a * c) / gcd(a, c);

	ans += max((long long)0, (n / lcm) - 1) * (lcm / a) * b;
	n -= (ans / b) * a;

	long long ac = 0, t = LLONG_MAX;
	while (1) {
		t = min(t, ac * b + ((n - ac * a + c - 1 >= 0 ? ((n - ac * a + c - 1) / c) * d : 0)));
		if (ac * a > n) break;
		ac++;
	}
	cout << ans + t;
}
