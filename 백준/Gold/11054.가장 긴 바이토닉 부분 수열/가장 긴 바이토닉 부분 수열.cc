#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	int a[1001] = { 0, };
	int dp1[1001] = { 0, }; //증가
	int dp2[1001] = { 0, }; //감소

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		dp1[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j])
				dp1[i] = max(dp1[i], dp1[j] + 1);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp1[i] + dp2[i] - 1);
	}
	cout << ans;
}