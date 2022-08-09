#include <iostream>
using namespace std;

string s1, s2, s3;
int dp[101][101][101];

int getMax(int a, int b, int c, int d, int e, int f) {
	return max(a, max(b, max(c, max(d, max(e, f)))));
}

int main() {
	cin >> s1 >> s2 >> s3;
	int ans = 0;
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			for (int k = 1; k <= s3.length(); k++) {
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else {
					dp[i][j][k] = max(dp[i][j][k], getMax(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1], dp[i - 1][j - 1][k], dp[i][j - 1][k - 1], dp[i - 1][j][k - 1]));
				}
				ans = max(ans, dp[i][j][k]);
			}
		}
	}
	cout << ans;
}