#include <iostream>
using namespace std;

long long n;

bool get(long long k) {
	for (long long i = 2; i * i <= k; i++) {
		if (k % i == 0)return false;
	}

	return true;
}

int main() {
	int t; cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n == 0 || n == 1) {
			cout << 2 << '\n';
			continue;
		}
		for (long long j = n;; j++) {
			if (get(j)) {
				cout << j << '\n';
				break;
			}
		}
	}
}