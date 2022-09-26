#include <iostream>
#include <algorithm>
using namespace std;

int n, a[50];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] + a[i + 1] > a[j]) {
				ans = max(ans, j - i + 1);
			}
		}
	}

	cout << max(ans, min(n, 2));
}