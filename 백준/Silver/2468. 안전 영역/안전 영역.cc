#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, maxPool, visit[100][100];
vector<vector<int>> map;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };

int bfs(int pool) {
	vector<vector<int>> t = map;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] <= pool)t[i][j] = 0;
		}
	}
	int res = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && t[i][j] != 0) {
				res++;
				visit[i][j] = 1;
				q.push({ i,j });
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && t[nx][ny] != 0) {
							visit[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
	}
	memset(visit, 0, sizeof(visit));
	return res;
}

int main() {
	cin >> n;
	map.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			maxPool = max(maxPool, map[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= maxPool; i++) {
		ans = max(ans, bfs(i));
	}
	cout << ans;
}