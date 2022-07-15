#include <iostream>
#include <algorithm>
using namespace std;

int a[10000], dif[10000];
int n, k;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] += 10000;
	}
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		dif[i] = a[i + 1] - a[i];
	}
	sort(dif, dif + n - 1);
	int ans = 0;
	for (int i = 0; i < n - k; i++) {
		ans += dif[i];
	}
	cout << ans;
}