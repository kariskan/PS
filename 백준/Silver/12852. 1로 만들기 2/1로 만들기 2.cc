#include <iostream>
using namespace std;
pair<int, int> dp[1000001];
int main() {
	int n;
	cin >> n;
	dp[1].first = 1;
	for (int i = 2; i <= n; i++)dp[i].first = -1;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0 && (dp[i].first == -1 || dp[i].first > dp[i / 2].first + 1)) {
			dp[i].first = dp[i / 2].first + 1;
			dp[i].second = i / 2;
		}
		if (i % 3 == 0 && (dp[i].first == -1 || dp[i].first > dp[i / 3].first + 1)) {
			dp[i].first = dp[i / 3].first + 1;
			dp[i].second = i / 3;
		}
		if (dp[i].first == -1 || dp[i].first > dp[i - 1].first + 1) {
			dp[i].first = dp[i - 1].first + 1;
			dp[i].second = i - 1;
		}
	}
	cout << dp[n].first - 1 << "\n";
	while (n) {
		cout << n << " ";
		n = dp[n].second;
	}
}