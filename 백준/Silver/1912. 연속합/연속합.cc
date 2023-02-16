#include <iostream>
using namespace std;
int a[100000], d[100000];
int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	d[0] = a[0];
	int ans = d[0];
	for (int i = 1; i < n; i++) {
		d[i] = max(d[i - 1] + a[i], a[i]);
		ans = max(ans, d[i]);
	}
	cout << ans;
}