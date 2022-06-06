#include <iostream>

using namespace std;
#define mod 1000000007
int n;
long long gcd(long long a, long long b) {
	if (a == 0)return b;
	return gcd(b % a, a);
}
long long run(long long x, long long k) {
	if (k == 1)return x;
	if (k & 1) return x * run(x, k - 1) % mod;
	long long res = run(x, k / 2);
	return res * res % mod;
}
int main() {
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		ans += (b * (run(a, mod - 2))) % mod;
	}
	cout << ans % mod;
}