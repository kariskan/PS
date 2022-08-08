#include <iostream>
using namespace std;

int a[1001], dp[1001][31][3]; //i초에 j번 움직였고, k위치에 있을 때 먹을 수 있는 최대의 자두 개수

int main() {

	int t, w; cin >> t >> w;

	for (int i = 1; i <= t; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j <= min(i, w); j++) {
			if (j % 2 == 0) {
				dp[i][j][1] = max(dp[i][j][1], max(dp[i][j - 1][2], dp[i - 1][j][1])) + (a[i] == 1 ? 1 : 0);
			}
			else {
				dp[i][j][2] = max(dp[i][j][2], max(dp[i][j - 1][1], dp[i - 1][j][2])) + (a[i] == 2 ? 1 : 0);
			}
		}
	}

	cout << max(dp[t][w][1], dp[t][w][2]);
}