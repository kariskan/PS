#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 0;; i++) {
		int t = n + i;
		int cnt = 0;
		while (t) {
			if (t % 2 != 0)cnt++;
			t /= 2;
		}
		if (cnt <= m) {
			ans = i;
			break;
		}
	}

	cout << ans;
}