#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char map[50][50];
int visit[50][50][4], n;

int x[4] = { 0,1,0,-1 };
int y[4] = { 1,0,-1,0 };

bool check(int i, int j, int dir) {
	i += x[dir];
	j += y[dir];
	return (i >= 0 && i < n&& j >= 0 && j < n&& map[i][j] != '*' && visit[i][j][dir] == -1);
}

int main() {

	cin >> n;

	int sx = -1, sy, dx, dy;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				if (sx == -1) {
					sx = i; sy = j;
				}
				else {
					dx = i; dy = j;
				}
			}
			visit[i][j][0] = visit[i][j][1] = visit[i][j][2] = visit[i][j][3] = 2500;
		}
	}

	queue<pair<pair<int, int>, int>> q; //i, j, dir

	for (int i = 0; i <= 3; i++) {
		q.push({ {sx,sy},i });
		visit[sx][sy][i] = 0;
	}

	while (!q.empty()) {

		int a = q.front().first.first;
		int b = q.front().first.second;
		int dir = q.front().second;
		q.pop();

		int nx = a + x[dir];
		int ny = b + y[dir];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] != '*') {

			if (map[nx][ny] == '!') {
				for (int i = 1; i <= 3; i += 2) {
					if (visit[nx][ny][(dir + i) % 4] > visit[a][b][dir] + 1) {
						visit[nx][ny][(dir + i) % 4] = visit[a][b][dir] + 1;
						q.push({ {nx,ny},(dir + i) % 4 });
					}
				}
			}

			if (visit[nx][ny][dir] > visit[a][b][dir]) {
				q.push({ {nx,ny},dir });
				visit[nx][ny][dir] = visit[a][b][dir];
			}
		}
	}


	int ans = -1;
	for (int i = 0; i < 4; i++) {
		if (visit[dx][dy][i] == -1)continue;
		if (ans == -1 || visit[dx][dy][i] < ans)ans = visit[dx][dy][i];
	}
	cout << ans;
}