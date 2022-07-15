#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[1000] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int ans;
	if (a[0] > 1)ans = 1;
	else {
		int sum = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] > sum + 1) {
				ans = sum + 1;
				break;
			}
			sum += a[i];
			ans = sum + 1;
		}
	}
	cout << ans;
}