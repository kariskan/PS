#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int board[1000][1000];
int visit[1001][1001][11][2]; //0일때 낮, 1일때 밤
int x[5] = { 0,0,0,1,-1 };
int y[5] = { 0,1,-1,0,0 };
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	queue<tuple<int, int, int, int>> q;
	visit[0][0][0][0] = 1;
	q.push({ 0,0,0,0 });
	while (!q.empty()) {
		int a, b, c, d;
		tie(a, b, c, d) = q.front(); q.pop();
		for (int i = 0; i < 5; i++) {
			int nx = a + x[i];
			int ny = b + y[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (board[nx][ny] == 0 && !visit[nx][ny][c][1 - d]) {
					visit[nx][ny][c][1 - d] = visit[a][b][c][d] + 1;
					q.push({ nx,ny,c,1 - d });
				}
				else if (board[nx][ny] == 1 && c != k) {
					if (d == 0) {
						if (!visit[nx][ny][c + 1][1 - d]) {
							visit[nx][ny][c + 1][1 - d] = visit[a][b][c][d] + 1;
							q.push({ nx,ny,c + 1, 1 - d });
						}
					}
					else {
						if (i == 0 && !visit[a][b][c][1 - d]) {
							visit[a][b][c][1 - d] = visit[a][b][c][d] + 1;
							q.push({ a,b,c,1 - d });
						}
					}
				}
			}
		}
	}
	if (n == 1 && m == 1)cout << 1;
	else {
		int ans = -1;
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j < 2; j++) {
				if (visit[n - 1][m - 1][i][j] == 0)continue;
				if (ans == -1 || ans > visit[n - 1][m - 1][i][j])
					ans = visit[n - 1][m - 1][i][j];
			}
		}
		cout << ans;
	}
}