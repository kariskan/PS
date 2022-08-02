#include <iostream>
#include <vector>
#include <string>
using namespace std;

int a[10] = { 6,2,5,5,4,5,6,3,7,6 };
long long dp[101];
int t, n;

int main() {
	cin >> t;
	for (int i = 1; i <= 100; i++) {
		dp[i] = 10000000000000000;
	}
	dp[2] = 1; dp[3] = 7; dp[4] = 4; dp[5] = 2; dp[6] = 6; dp[7] = 8;
	for (int i = 8; i <= 100; i++) {
		for (int j = 2; j <= 7; j++) {
			dp[i] = min(dp[i], dp[i - j] * 10 + (j == 6 ? 0 : dp[j]));
		}
	}
	
	while (t--) {
		cin >> n;
		int asdf = n;
		string s1 = "";
		if (n % 2 != 0) {
			s1 += "7";
			asdf -= 3;
		}
		for (int i = 0; i < asdf / 2; i++)s1 += "1";
		cout << dp[n] << ' ' << s1 << '\n';
	}
}