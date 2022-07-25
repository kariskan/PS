#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int n, m;
char map[50][50];
int visit[50][50][64];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
queue<tuple<int, int, int>> q;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				q.push({ i,j,0 });
				visit[i][j][0] = 1;
			}
		}
	}
	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front();
		q.pop();

		if (map[a][b] == '1') {
			cout << visit[a][b][c] - 1;
			return 0;
		}

		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (map[nx][ny] != '#') {
					if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z') {
						if (!visit[nx][ny][c | (1 << (map[nx][ny] - 'a'))]) {
							q.push({ nx,ny,c | (1 << (map[nx][ny] - 'a')) });
							visit[nx][ny][c | (1 << (map[nx][ny] - 'a'))] = visit[a][b][c] + 1;
						}
					}
					else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z') {
						if (c & (1 << (map[nx][ny] - 'A')) && !visit[nx][ny][c]) {
							q.push({ nx,ny,c });
							visit[nx][ny][c] = visit[a][b][c] + 1;
						}
					}
					else { // 출구
						if (!visit[nx][ny][c]) {
							q.push({ nx,ny,c });
							visit[nx][ny][c] = visit[a][b][c] + 1;
						}
					}
				}
			}
		}
	}
	cout << -1;
}