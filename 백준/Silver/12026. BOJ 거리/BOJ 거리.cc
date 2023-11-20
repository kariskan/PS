#include <iostream>
using namespace std;
char c[1002];
int dp[1002];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (i > 1 && c[i] == 'O') {
			dp[i] = (i - 1) * (i - 1);
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (c[i] == 'B' && c[j] == 'O') {
				if (dp[i] && (!dp[j] || dp[j] > dp[i] + (j - i) * (j - i))) {
					dp[j] = dp[i] + (j - i) * (j - i);
				}
			}
			if (c[i] == 'O' && c[j] == 'J') {
				if (dp[i] && (!dp[j] || dp[j] > dp[i] + (j - i) * (j - i))) {
					dp[j] = dp[i] + (j - i) * (j - i);
				}
			}
			if (c[i] == 'J' && c[j] == 'B') {
				if (dp[i] && (!dp[j] || dp[j] > dp[i] + (j - i) * (j - i))) {
					dp[j] = dp[i] + (j - i) * (j - i);
				}
			}
		}
	}
	if (n == 1)cout << 0;
	else if (dp[n])cout << dp[n];
	else cout << -1;
}