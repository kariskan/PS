#include <iostream>
#include <queue>
using namespace std;

int n, m, h, w, k, sx, sy, dx, dy;
int map[501][501], visit[501][501];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
queue<pair<int, int>> q;

int main() {
	cin >> n >> m >> h >> w >> k;
	
	for (int i = 0; i < k; i++) {
		int c, d; cin >> c >> d;
		map[c][d] = 1;
	}

	cin >> sx >> sy >> dx >> dy;

	q.push({ sx,sy });
	visit[sx][sy] = 1;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		if (a == dx && b == dy) {
			cout << visit[a][b] - 1;
			return 0;
		}

		for (int k = 0; k < 4; k++) {
			int ok = 1;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					int nx = a + i + x[k];
					int ny = b + j + y[k];
					if (!(nx > 0 && nx <= n && ny > 0 && ny <= m && map[nx][ny] != 1)) {
						ok = 0;
						break;
					}
				}
			}
			if (ok && !visit[a + x[k]][b + y[k]]) {
				q.push({ a + x[k],b + y[k] });
				visit[a + x[k]][b + y[k]] = visit[a][b] + 1;
			}
		}
	}

	cout << -1;
}