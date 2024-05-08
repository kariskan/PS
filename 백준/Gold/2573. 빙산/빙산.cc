#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
using namespace std;

int map[300][300], vis[300][300];
int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int t = 0;; t++) {
		int chunk = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] && !vis[i][j]) {
					vis[i][j] = 1;
					chunk++;

					queue<pair<int, int>> q;
					q.push({ i,j });
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (range(nx,ny) && !vis[nx][ny] && map[nx][ny]) {
								q.push({ nx,ny });
								vis[nx][ny] = 1;
							}
						}
					}
				}
			}
		}
		memset(vis, 0, sizeof(vis));
		if (chunk > 1) {
			cout << t;
			return 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j]) {
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (range(nx, ny) && !map[nx][ny]) {
							vis[i][j]++;
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = max(map[i][j] - vis[i][j], 0);
			}
		}
		if (chunk == 0) {
			cout << 0;
			return 0;
		}
		memset(vis, 0, sizeof(vis));
	}
}