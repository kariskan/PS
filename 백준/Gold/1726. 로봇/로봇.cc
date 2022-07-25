#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int map[101][101], visit[101][101][4];
int x[4] = { 0,-1,0,1 };
int y[4] = { 1,0,-1,0 };
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	int fx, fy, fd, tx, ty, td;
	queue<tuple<int, int, int>> q;
	cin >> fx >> fy >> fd >> tx >> ty >> td;
	fd--; td--;
	if (fd == 1) fd = 2;
	else if (fd == 2)fd = 3;
	else if (fd == 3)fd = 1;
	if (td == 1)td = 2;
	else if (td == 2)td = 3;
	else if (td == 3)td = 1;
	visit[fx][fy][fd] = 1;
	q.push({ fx,fy,fd });
	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front(); q.pop();
		if (tx == a && ty == b && td == c) {
			cout << visit[tx][ty][td] - 1;
			break;
		}
		for (int k = 1; k <= 3; k++) {
			int nx = a + x[c] * k;
			int ny = b + y[c] * k;
			if (map[nx][ny] == 1)break;
			if (nx > 0 && nx <= n && ny > 0 && ny <= m && !visit[nx][ny][c]) {
				visit[nx][ny][c] = visit[a][b][c] + 1;
				q.push({ nx,ny,c });
			}
		}
		if (!visit[a][b][(c + 1) % 4]) {
			visit[a][b][(c + 1) % 4] = visit[a][b][c] + 1;
			q.push({ a,b,(c + 1) % 4 });
		}
		int nc;
		if (c == 0)nc = 3;
		else nc = c - 1;
		if (!visit[a][b][nc]) {
			visit[a][b][nc] = visit[a][b][c] + 1;
			q.push({ a,b,nc });
		}
	}
}