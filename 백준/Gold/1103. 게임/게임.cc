#include <iostream>
using namespace std;

int n, m;
char map[50][50];
int visit[50][50], dp[50][50];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int go(int i, int j) {
	if (dp[i][j])return dp[i][j];
	int ret = 0;
	visit[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		int nx = i + x[k] * (map[i][j] - '0');
		int ny = j + y[k] * (map[i][j] - '0');
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != 'H') {
			if (visit[nx][ny]) {
				cout << -1;
				exit(0);
			}
			ret = max(ret, go(nx, ny));
		}
	}
	visit[i][j] = 0;
	return dp[i][j] = ret + 1;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	cout << go(0, 0);
}