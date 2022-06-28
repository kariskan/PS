#include <iostream>
#include <queue>
using namespace std;

int n, m, c;
int map[2000][2000], visit[2000][2000];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int stx, sty, dex = -1, dey = -1;
int main() {
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 4) {
				stx = i;
				sty = j;
			}
			if (map[i][j] == 2) {
				dex = i;
				dey = j;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && map[i][j] == 3) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				visit[i][j] = 1;
				map[i][j] = 1;
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();
					
					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny]) {
							if (abs(nx - i) + abs(ny - j) <= c) {
								q.push({ nx,ny });
								visit[nx][ny] = -1;
								if(map[nx][ny]==0) map[nx][ny] = 1;
							}
						}
					}
				}
			}
		}
	}
	queue<pair<int, int>> q;
	q.push({ stx,sty });
	visit[stx][sty] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] != 1) {
				q.push({ nx,ny });
				visit[nx][ny] = visit[a][b] + 1;
			}
		}
	}
	if (visit[dex][dey] == -1 || visit[dex][dey] == 0)cout << -1;
	else cout << visit[dex][dey] - 1;
}