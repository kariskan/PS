#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int n, m, t, map[100][100], visit[100][100][2];

int main() {
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	visit[0][0][0] = 1;
	int x[4] = { 0,0,1,-1 };
	int y[4] = { 1,-1,0,0 };
	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front();
		q.pop();

		if (visit[a][b][c] - 1 > t)continue;
		if (a == n - 1 && b == m - 1) {
			cout << visit[a][b][c] - 1;
			return 0;
		}

		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			int nc = c;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (c == 0 && map[nx][ny] == 1)continue;
				if (c == 0) {
					if (map[nx][ny] == 2)nc = 1;
					else nc = 0;
				}
				if (!visit[nx][ny][nc]) {
					q.push({ nx,ny,nc });
					visit[nx][ny][nc] = visit[a][b][c] + 1;
				}
			}
		}
	}
	cout << "Fail";
}