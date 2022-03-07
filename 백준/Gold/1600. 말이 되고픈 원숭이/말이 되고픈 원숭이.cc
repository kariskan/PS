#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int x[12] = { 0,0,1,-1,-1,-2,-2,-1,1,2,2,1 };
int y[12] = { 1,-1,0,0,2,1,-1,-2,2,1,-1,-2 };
int board[200][200];
int visit[200][200][31];
int k, n, m;
int main() {
	cin >> k >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	queue<tuple<int, int, int>>q;
	q.push({ 0,0,0 });
	visit[0][0][0] = 1;
	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front(); q.pop();
		for (int i = 0; i < 12; i++) {
			int nx = a + x[i];
			int ny = b + y[i];
			if (c == k && i > 3)break;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != 1) {
				if (i <= 3) {
					if (visit[nx][ny][c])continue;
					visit[nx][ny][c] = visit[a][b][c] + 1;
					q.push({ nx,ny,c });
				}
				else {
					if (visit[nx][ny][c + 1])continue;
					visit[nx][ny][c + 1] = visit[a][b][c] + 1;
					q.push({ nx,ny,c + 1 });
				}
			}
		}
	}
	int ans = -1;
	if (n == 1 && m == 1)cout << 0;
	else {
		for (int i = 0; i <= k; i++) {
			if (visit[n - 1][m - 1][i]) {
				if (ans == -1 || ans > visit[n - 1][m - 1][i] - 1) {
					ans = visit[n - 1][m - 1][i] - 1;
				}
			}
		}
		cout << ans;
	}
}