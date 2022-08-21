#include <iostream>
using namespace std;

string a, b, s;
int dp[100][21][2]; //k==0일때 a, k==1일때 b를 지나며 i번째일 때 j번째 문자열

int main() {

	cin >> s >> a >> b;

	int n = a.length();

	for (int i = 0; i < n; i++) {
		if (s[0] == a[i])dp[i][0][0]++;
		if (s[0] == b[i])dp[i][0][1]++;
	}

	int ans = 0;

	for (int i = 1; i < s.length(); i++) {
		for (int j = 0; j < n; j++) {
			if (s[i] == a[j]) {
				for (int k = 0; k < j; k++) {
					dp[j][i][0] += dp[k][i - 1][1];
				}
			}
			if (s[i] == b[j]) {
				for (int k = 0; k < j; k++) {
					dp[j][i][1] += dp[k][i - 1][0];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		ans += dp[i][s.length() - 1][0] + dp[i][s.length() - 1][1];
	}

	cout << ans;

	return 0;
}