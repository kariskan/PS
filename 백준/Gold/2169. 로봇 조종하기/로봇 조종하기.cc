#include <iostream>
#include <vector>
using namespace std;

int map[1000][1000], dp[1000][1000];

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			dp[i][j] = -100000;
		}
	}

	dp[0][0] = map[0][0];
	for (int i = 1; i < m; i++) {
		dp[0][i] = dp[0][i - 1] + map[0][i];
	}

	for (int i = 1; i < n; i++) {
		vector<int> t1(m), t2(m);
		t1[0] = dp[i - 1][0] + map[i][0];
		for (int j = 1; j < m; j++) {
			t1[j] = max(dp[i - 1][j], t1[j - 1]) + map[i][j];
		}
		t2[m - 1] = dp[i - 1][m - 1] + map[i][m - 1];
		for (int j = m - 2; j >= 0; j--) {
			t2[j] = max(dp[i - 1][j], t2[j + 1]) + map[i][j];
		}
		for (int j = 0; j < m; j++) {
			dp[i][j] = max(t1[j], t2[j]);
		}
	}
	cout << dp[n - 1][m - 1];
}