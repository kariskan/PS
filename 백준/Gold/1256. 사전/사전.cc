#include <iostream>
#include <cstring>
using namespace std;

long long dp[201][101];

long long comb(int n, int r) {
	if (n == r || r == 0)return 1;
	if (dp[n][r] != -1)return dp[n][r];
	long long ret1 = 0, ret2 = 0;
	ret1 = comb(n - 1, r - 1);
	ret2 = comb(n - 1, r);
	if (ret1 + ret2 > 1000000000)return dp[n][r] = 1000000001;
	else return dp[n][r] = ret1 + ret2;
}

void go(int n, int m, long long k) {
	long long c = comb(n + m - 1, n - 1);
	if (n > 0 && k <= c) {
		cout << 'a';
		go(n - 1, m, k);
	}
	else if (m > 0) {
		cout << 'z';
		go(n, m - 1, k - c);
	}
}

int main() {
	int n, m;
	long long k;
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	if (comb(n + m, n) < k)cout << -1;
	else go(n, m, k);
}