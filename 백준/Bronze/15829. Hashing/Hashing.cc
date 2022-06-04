#include <iostream>
#include <cmath>
#define mod 1234567891
using namespace std;

int main() {
	int n;
	cin >> n;
	long long ans = 0, r = 1;;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		ans = (ans % mod + ((c - 'a' + 1) * r) % mod) % mod;
		r = r * 31 % mod;
	}
	cout << ans;
}