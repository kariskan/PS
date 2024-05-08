#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n;
		vector<int> money;
		for (int i = 0; i < n; i++) {
			int a; 
			cin >> a;
			money.push_back(a);
		}
		cin >> m;

		// 1 1 1 1 1 1 1 1
		// 1 1 2 2 3 3
		int dp[10001] = { 1, };
		for (int i = 0; i < n; i++) {
			for (int j = money[i]; j <= m; j++) {
				dp[j] += dp[j - money[i]];
			}
		}

		cout << dp[m] << '\n';
	}
}