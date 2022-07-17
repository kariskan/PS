#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, i + a[n - i + 1]);
	}
	cout << ans + 1;
}