#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int n, m, sx, sy, dx, dy;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int map[1001][1001], visit[2][1001][1001];
queue<tuple<int, int, int>> q;

int main() {
	cin >> n >> m >> sx >> sy >> dx >> dy;
	visit[0][sx][sy] = 1;
	q.push({ 0,sx,sy });

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front();
		q.pop();

		if (b == dx && c == dy) {
			cout << visit[a][b][c] - 1;
			return 0;
		}

		for (int k = 0; k < 4; k++) {
			int nx = b + x[k];
			int ny = c + y[k];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
				if (a == 0) {
					if (map[nx][ny] == 0) {
						if (!visit[0][nx][ny]) {
							visit[0][nx][ny] = visit[a][b][c] + 1;
							q.push({ 0,nx,ny });
						}
					}
					else {
						if (!visit[1][nx][ny]) {
							visit[1][nx][ny] = visit[a][b][c] + 1;
							q.push({ 1,nx,ny });
						}
					}
				}
				else {
					if (!visit[1][nx][ny] && map[nx][ny] == 0) {
						visit[1][nx][ny] = visit[a][b][c] + 1;
						q.push({ a,nx,ny });
					}
				}
			}
		}
	}

	cout << -1;
}