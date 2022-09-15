#include <iostream>
#include <vector>
using namespace std;

int map[1001][1001], dp[1001][1001], n;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int m; cin >> m;
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			map[i][a] = 1;
			if (i == 1) dp[i][a] = 1;
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			if (!map[i][j]) continue;
			for (int k = 1; k <= 9; k++) {
				if (j != k) {
					if (dp[i - 1][k]) {
						dp[i][j] = k;
						break;
					}
				}
			}
		}
	}

	vector<int> v;
	int k = 0;
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= 9; j++) {
			if (dp[i][j] && k != j) {
				k = j;
				v.push_back(j);
				break;
			}
		}
	}

	if (v.size() != n) cout << -1;
	else {
		for (int i = v.size() - 1; i >= 0; i--) {
			cout << v[i] << '\n';
		}
	}
}