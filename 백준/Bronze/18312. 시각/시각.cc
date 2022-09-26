#include <iostream>
using namespace std;

int n, k;

bool contain(int a) {
	if (a < 10 && k == 0) return true;
	while (a) {
		if (a % 10 == k) return true;
		a /= 10;
	}
	return false;
}

int main() {
	cin >> n >> k;

	int ans = 0;

	for (int h = 0; h <= n; h++) {
		for (int m = 0; m < 60; m++) {
			for (int s = 0; s < 60; s++) {
				if (contain(h) || contain(m) || contain(s)) {
					ans++;
				}
			}
		}
	}

	cout << ans;
}