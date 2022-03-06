#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int board[1000][1000];
int visit[1001][1001][11];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	queue<tuple<int, int, int>> q;
	visit[0][0][0] = 1;
	q.push({ 0,0,0 });
	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = a + x[i];
			int ny = b + y[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (board[nx][ny] == 0 && visit[nx][ny][c] == 0) {
					visit[nx][ny][c] = visit[a][b][c] + 1;
					q.push({ nx,ny,c });
				}
				else if (board[nx][ny] == 1 && !visit[nx][ny][c + 1] && c != k) {
					visit[nx][ny][c + 1] = visit[a][b][c] + 1;
					q.push({ nx,ny,c + 1 });
				}
			}
		}
	}
	if (n == 1 && m == 1)cout << 1;
	else {
		int ans = -1;
		for (int i = 0; i <= k; i++) {
			if (visit[n - 1][m - 1][i] == 0)continue;
			if (ans == -1 || ans > visit[n - 1][m - 1][i])
				ans = visit[n - 1][m - 1][i];
		}
		cout << ans;
	}
}