#include <iostream>
#include <algorithm>
using namespace std;
int a[200001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long dis = 0;
	int ans = a[0];
	for (int i = 0; i < n; i++) {
		dis += a[i] - a[0];
	}
	long long minDis = dis;
	for (int i = 1; i < n; i++) {
		long long temp = dis - (a[i] - a[i - 1]) + i * (a[i] - a[i - 1]) - (n - i - 1) * (a[i] - a[i - 1]);
		if (minDis > temp) {
			minDis = temp;
			ans = a[i];
		}
		dis = temp;
	}
	cout << ans;
}