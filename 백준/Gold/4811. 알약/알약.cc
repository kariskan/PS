#include <iostream>
using namespace std;
long long dp[31][31];

long long go(int w, int h) {
	if (w == 0 || h == 0)return 1;
	if (dp[w][h])return dp[w][h];
	long long ret = 0;
	if (h > w)ret += go(w, h - 1);
	ret += go(w - 1, h);
	return dp[w][h] = ret;
}

int main() {
	
	go(30, 30);

	while (1) {
		int n; cin >> n;
		if (n == 0)break;
		cout << dp[n][n] << '\n';
	}
}