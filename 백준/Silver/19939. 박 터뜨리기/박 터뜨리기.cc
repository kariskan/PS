#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int ans = -1;
	if (n >= (k * (k + 1)) / 2) {
		int num = k;
		for (int i = 1;; i++) {
			if ((num + 1) * (num + 2) / 2 - (num - k + 1) * (num - k + 2) / 2 > n)break;
			num++;
		}
		if (num * (num + 1) / 2 - (num - k) * (num - k + 1) / 2 == n)cout << k - 1;
		else cout << k;
	}
	else cout << -1;
}