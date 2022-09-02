#include <iostream>
#include <cmath>
using namespace std;

int dp[200001][21];

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		dp[i][0] = a;
	}

	for (int j = 1; j <= 20; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}

	int q; cin >> q;

	for (int i = 0; i < q; i++) {
		
		int a, b; cin >> a >> b;

		for (int i = 20; i >= 0; i--) {
			int k = pow(2, i);
			if (a >= k) {
				a -= k;
				b = dp[b][i];
			}
		}

		cout << b << '\n';
	}
}