#include <iostream>
#include <algorithm>
using namespace std;

int a[100000], n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = n - 1; i >= 0; i -= 3) {
		if (i >= 2) ans += a[i] + a[i - 1];
		else {
			for (int j = i; j >= 0; j--)ans += a[j];
			break;
		}
	}
	cout << ans;
}