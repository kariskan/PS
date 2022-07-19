#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	int a[10000];
	for (int i = 0; i < n * 2; i++) {
		cin >> a[i];
	}
	sort(a, a + n * 2);
	int ans = 100000000;
	for (int i = 0; i < n * 2; i++) {
		ans = min(ans, a[i] + a[n * 2 - i - 1]);
	}
	cout << ans;
}
