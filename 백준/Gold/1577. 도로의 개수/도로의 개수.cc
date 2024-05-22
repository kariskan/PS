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

long long dp[101][101];
set <pair<pair<int, int>, pair<int, int>>> se;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		se.insert({ {min(a,c),min(b,d)},{max(a,c),max(b,d)} });
	}

	for (int j = 1; j <= m; j++) {
		if (se.find({ {0,j - 1},{0,j} }) == se.end()) {
			dp[0][j] = 1;
		}
		else {
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (se.find({ {i - 1,0},{i,0} }) == se.end()) {
			dp[i][0] = 1;
		}
		else {
			break;
		}
	}

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (se.find({ {i - 1,j},{i,j} }) == se.end()) {
				dp[i][j] += dp[i - 1][j];
			}
			if (se.find({ {i,j - 1},{i,j} }) == se.end()) {
				dp[i][j] += dp[i][j - 1];
			}
		}
	}

	cout << dp[n][m];
}