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

long long n, a[100][100], dp[100][100];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n - 1 && j == n - 1) {
				continue;
			}
			if (i + a[i][j] < n) {
				dp[i + a[i][j]][j] += dp[i][j];
			}
			if (j + a[i][j] < n) {
				dp[i][j + a[i][j]] += dp[i][j];
			}
		}
	}

	cout << dp[n - 1][n - 1];
}