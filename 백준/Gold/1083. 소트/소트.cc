#include <iostream>
#include <algorithm>
using namespace std;

int n, a[50], s, b[50];

bool compare(int& a, int& b) {
	return a > b;
}

bool isLast() {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i])return false;
	}

	return true;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b, b + n, compare);

	cin >> s;
	int idx = 0;

	while (s) {
		if (isLast()) break;

		int maxIdx = 0, m = 0;

		for (int j = idx; j <= min(n - 1, idx + s); j++) {
			if (m < a[j]) {
				m = a[j];
				maxIdx = j;
			}
		}

		for (int j = maxIdx - 1; j >= idx; j--) {
			swap(a[j], a[j + 1]);
		}

		if (s > maxIdx - idx) {
			s -= (maxIdx - idx);
			idx++;
		}
		else break;
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
}