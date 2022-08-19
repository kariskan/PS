#include <iostream>
#include <cstring>
using namespace std;

int n, a[1010], dp[1010][1010];

int go(int l, int r) {

	if (l > r)return 0;
	if (dp[l][r])return dp[l][r];

	if ((n - r + l) % 2 != 0) { //1턴
		return dp[l][r] = max(a[l] + go(l + 1, r), a[r] + go(l, r - 1));
	}
	else { //2턴
		return dp[l][r] = min(go(l + 1, r), go(l, r - 1));
	}

}

int main() {

	int t; cin >> t;
	
	while (t--) {

		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));

		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		cout << go(1, n) << '\n';
	}
	return 0;
}