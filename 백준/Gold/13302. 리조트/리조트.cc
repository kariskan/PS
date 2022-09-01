#include <iostream>
using namespace std;

int n, m, a[101], dp[101][101];

int go(int day, int coupon) {

	if (day > n) return 0;
	if (dp[day][coupon]) return dp[day][coupon];

	int ret = 1000000000;

	if (a[day]) ret = go(day + 1, coupon);
	else {
		ret = min(ret, go(day + 1, coupon) + 10);
		ret = min(ret, go(day + 3, coupon + 1) + 25);
		ret = min(ret, go(day + 5, coupon + 2) + 37);
		
		if (coupon >= 3) ret = min(ret, go(day + 1, coupon - 3));
	}

	return dp[day][coupon] = ret;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int c; cin >> c;
		a[c] = 1;
	}

	cout << go(1, 0) * 1000;
}