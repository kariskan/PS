#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[51] = { 0, };
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	
	for (int i = 1; i <= n; i++) {
		if (a[i] < 0) {
			if (i < n && a[i + 1] <= 0) {
				ans += a[i] * a[i + 1];
				i++;
			}
			else ans += a[i];
		}
		else if (a[i] == 0) {
			continue;
		}
		else {
			if (n % 2 != i % 2 && i < n && a[i] != 1) {
				ans += a[i] * a[i + 1];
				i++;
			}
			else ans += a[i];
		}
	}
	cout << ans;
}