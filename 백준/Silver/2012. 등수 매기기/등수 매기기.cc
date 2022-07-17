#include <iostream>
#include <algorithm>
using namespace std;
int n, a[500000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(i + 1 - a[i]);
	}
	cout << ans;
}