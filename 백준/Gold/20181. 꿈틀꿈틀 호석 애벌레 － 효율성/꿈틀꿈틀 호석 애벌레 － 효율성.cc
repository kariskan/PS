#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

long long dp[100001], a[100001], s[100001], n, k;

long long go(int idx) {
	if (idx > n) {
		return 0;
	}
	if (dp[idx] != -1) {
		return dp[idx];
	}
	long long sum = 0, t = idx;
	int l = idx, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (s[mid] - s[idx - 1] >= k) {
			t = mid;
			sum = s[mid] - s[idx - 1];
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	if (sum < k) {
		return dp[idx] = 0;
	}
	long long ret = go(t + 1) + sum - k;
	return dp[idx] = max(go(idx + 1), ret);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		s[i] += s[i - 1] + a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << go(1);
}