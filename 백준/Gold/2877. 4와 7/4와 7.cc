#include <iostream>
#include <cmath>
using namespace std;

int n, a[31];
string s = "";

int main() {
	cin >> n;

	for (int i = 1; i <= 30; i++) {
		a[i] = a[i - 1] + pow(2, i);
	}

	while (n) {
		int k, idx;
		for (int i = 30; i >= 0; i--) {
			if (a[i] < n) {
				k = a[i];
				idx = i;
				break;
			}
		}

		if ((a[idx] + 1 + a[idx + 1]) / 2 < n) {
			s += '7';
			n -= pow(2, idx + 1);
		}
		else {
			s += '4';
			n -= pow(2, idx);
		}

	}

	cout << s;
}