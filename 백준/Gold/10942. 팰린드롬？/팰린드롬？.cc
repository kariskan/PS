#include <iostream>
using namespace std;
int a[2000];
int dp[2000][2000];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		dp[i][i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (j > i + 1) {
				if (dp[i + 1][j - 1]) {
					dp[i][j] = a[i] == a[j];
				}
			}
			else {
				dp[i][j] = a[i] == a[j];
			}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << dp[x - 1][y - 1] << "\n";
	}
}