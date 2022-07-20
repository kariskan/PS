#include <iostream>
using namespace std;

int a[100001], sum[100001], n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] += sum[i - 1] + a[i];
	}
	int ans = 0;
	//벌 벌 꿀
	for (int i = 2; i < n; i++) {
		ans = max(ans, sum[n] - a[1] - a[i] + sum[n] - sum[i]);
	}
	//꿀 벌 벌
	for (int i = n - 1; i > 1; i--) {
		ans = max(ans, sum[n] - a[n] - a[i] + sum[i] - a[i]);
	}
	//벌 꿀 벌
	for (int i = 2; i < n; i++) {
		ans = max(ans, sum[i] - a[1] + sum[n - 1] - sum[i - 1]);
	}
	cout << ans;
}