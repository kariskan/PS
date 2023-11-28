#include <iostream>
#include <queue>
using namespace std;

int n, m, h, w, sx, sy, dx, dy;
int board[1001][1001];
int visit[1001][1001];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	cin >> h >> w >> sx >> sy >> dx >> dy;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 1) {
				for (int k = max(1, i - h + 1); k <= i; k++) {
					for (int l = max(1, j - w + 1); l <= j; l++) {
						if (!visit[k][l])visit[k][l] = -1;
					}
				}
			}
		}
	}
	if (visit[sx][sy]) {
		cout << -1;
		return 0;
	}
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visit[sx][sy] = 1;
	while (!q.empty()) {
		int a, b;
		a = q.front().first;
		b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x[i] + a;
			int ny = y[i] + b;
			if (nx > 0 && nx <= n && ny > 0 && ny <= m && !visit[nx][ny] && nx + h - 1 <= n && ny + w - 1 <= m) {
				q.push({ nx,ny });
				visit[nx][ny] = visit[a][b] + 1;
			}
		}
	}
	if (!visit[dx][dy] || visit[dx][dy] == -1)cout << -1;
	else cout << visit[dx][dy] - 1;
}