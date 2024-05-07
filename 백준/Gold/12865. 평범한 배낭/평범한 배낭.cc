#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, dp[100001];
pair<int, int> a[101];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = k; j >= a[i].first; j--) {
			dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
		}
	}

	cout << dp[k];
}