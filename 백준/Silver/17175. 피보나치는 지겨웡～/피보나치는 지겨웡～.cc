#include <iostream>
using namespace std;

long long dp[51];

long long go(int k) {
	if (dp[k]) return dp[k];
	long long ret = (go(k - 1) % 1000000007 + go(k - 2) % 1000000007) % 1000000007;
	return dp[k] = (ret + 1) % 1000000007;
}

int main() {
	int n; cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 3;

	cout << go(n) % 1000000007;
}