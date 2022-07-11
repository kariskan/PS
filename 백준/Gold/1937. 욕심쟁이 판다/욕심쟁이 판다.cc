#include <iostream>
using namespace std;

int n;
int map[500][500], dp[500][500];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int go(int i, int j) {
	if (dp[i][j])return dp[i][j];
	int res = 0;
	for (int k = 0; k < 4; k++) {
		int nx = i + x[k];
		int ny = j + y[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] < map[i][j]) {
			res = max(res, go(nx, ny));
		}
	}
	
	dp[i][j] = res + 1;
	return dp[i][j];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, go(i, j));
		}
	}
	cout << ans;
}