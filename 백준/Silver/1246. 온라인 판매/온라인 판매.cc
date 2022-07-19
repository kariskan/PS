#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[1000];

int main() {
	cin.sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a, a + m);
	int ans = 0, price = 0;
	for (int i = 0; i < m; i++) {
		if (ans < min(n, m - i) * a[i]) {
			ans = min(n, m - i) * a[i];
			price = a[i];
		}
	}
	cout << price << ' ' << ans;
}