#include <iostream>
using namespace std;

int idx[1000001];
int a[1000001];
int dp[1000001];
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		idx[a[i]] = i;
	}
	int ans = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (idx[i] > idx[i - 1]) {
			dp[i] = dp[i - 1] + 1;
		}
		else dp[i] = 1;
		ans = max(ans, dp[i]);
	}
	cout << n - ans;
}