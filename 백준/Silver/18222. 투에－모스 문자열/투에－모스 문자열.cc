#include <iostream>
#include <cmath>
using namespace std;

long long k;

void go(long long n, int cnt) {
	if (n == 1) {
		if (cnt % 2 == 0)cout << 0;
		else cout << 1;
		return;
	}
	else if (n == 2) {
		if (cnt % 2 == 0)cout << 1;
		else cout << 0;
		return;
	}
	for (long long i = 62; i >= 1; i--) {
		if ((long long)pow(2, i) < n) {
			go(n - (long long)pow(2, i), 1 - cnt);
			break;
		}
	}
}

int main() {
	cin >> k;

	go(k, 0);
}