#include <iostream>
using namespace std;

long long a, b;

int main() {
	cin >> a >> b;
	long long ans = a;

	for (long long i = a + 1; i <= b; i++) {
		if (b - i + 1 >= 4 && i % 4 == 0) {
			i += ((b - i + 1) / 4) * 4 - 1;
			continue;
		}
		ans ^= i;
	}
	cout << ans;
}