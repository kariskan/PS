#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int map[100][100];
int visit[100][100];
int g[100][100];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int index = 1;

void dfs(int i, int j) { 
	for (int i1 = 0; i1 < 4; i1++) {
		int nextX = x[i1] + i;
		int nextY = y[i1] + j;
		if (!g[nextX][nextY] && map[nextX][nextY] == 1 && nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
			g[nextX][nextY] = g[i][j];
			visit[i][j] = 1;
			dfs(nextX, nextY);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!g[i][j] && map[i][j] == 1) {
				g[i][j] = index++;
				dfs(i, j);
			}
		}
	}

	int ans = -1;
	queue<pair<int,int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = -1;
			if (map[i][j]) {
				q.push({ i,j });
				visit[i][j] = 0; 
			}
		}
	}

	while (!q.empty()) {
		int a1 = q.front().first;
		int a2 = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x[k] + a1;
			int ny = y[k] + a2;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (visit[nx][ny] == -1) {
					visit[nx][ny] = visit[a1][a2] + 1;
					g[nx][ny] = g[a1][a2];
					q.push({ nx,ny });
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int a1 = i + x[k];
				int a2 = j + y[k];

				if (a1 >= 0 && a1 < n && a2 >= 0 && a2 < n) {
					if (g[i][j] != g[a1][a2]) {
						if (ans == -1 || ans > visit[i][j] + visit[a1][a2]) {
							ans = visit[i][j] + visit[a1][a2];
						}
					}
				}
			}
		}
	}
	cout << ans;
}