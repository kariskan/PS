#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;
char map[30][30][30];
int visit[30][30][30];
int x[6] = { 0,0,1,-1,0,0 };
int y[6] = { 1,-1,0,0,0,0 };
int z[6] = { 0,0,0,0,-1,1 };
int main() {
	while (1) {
		int l, r, c;
		int sz, sx, sy, dz, dx, dy;
		cin >> l >> r >> c;
		if (!l && !r && !c)return 0;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S') {
						sz = i; sx = j; sy = k;
					}
					if (map[i][j][k] == 'E') {
						dz = i; dx = j; dy = k;
					}
				}
			}
		}
		int ok = 0;
		queue<tuple<int, int, int>> q;
		visit[sz][sx][sy] = 1;
		q.push({ sz,sx,sy });
		while (!q.empty()) {
			int a, b, d;
			tie(a, b, d) = q.front();
			q.pop();
			if (a == dz && b == dx && d == dy) {
				cout << "Escaped in " << visit[a][b][d] - 1 << " minute(s).\n";
				ok = 1;
				break;
			}
			for (int k = 0; k < 6; k++) {
				int nz = a + z[k];
				int nx = b + x[k];
				int ny = d + y[k];
				if (nz >= 0 && nz < l && nx >= 0 && nx < r && ny >= 0 && ny < c && !visit[nz][nx][ny] && map[nz][nx][ny] != '#') {
					visit[nz][nx][ny] = visit[a][b][d] + 1;
					q.push({ nz,nx,ny });
				}
 			}
		}
		if (!ok)cout << "Trapped!\n";
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));
	}
	
}