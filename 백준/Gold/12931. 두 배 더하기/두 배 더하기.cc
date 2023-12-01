#include <iostream>
using namespace std;

int a[50], n;

bool check() {
	for (int i = 0; i < n; i++) {
		if (a[i] != 0) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	while (!check()) {
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 1) {
				a[i]--;
				ans++;
			}
		}

		for (int i = 0; i < n; i++) {
			if (a[i]) {
				ans++;
				for (int j = i; j < n; j++) {
					a[j] /= 2;
				}
				break;
			}
		}
	}

	cout << ans;
}