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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// -97 -6 -2 6 98
	// -24 -6 -3 -2 61 98 100

	long long a[100], dp[100][21] = { 0, };
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	dp[0][a[0]] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j + a[i] >= 0 && j + a[i] <= 20) {
				dp[i][j + a[i]] += dp[i - 1][j];
			}
			if (j - a[i] >= 0 && j - a[i] <= 20) {
				dp[i][j - a[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[n - 2][a[n - 1]];
}