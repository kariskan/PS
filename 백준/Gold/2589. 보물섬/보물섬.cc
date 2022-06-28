#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int map[50][50];
int visit[50][50];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			if (c == 'L')map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	int ans = 0;
	int x[4] = { 0,0,1,-1 };
	int y[4] = { 1,-1,0,0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) {
				queue<pair<int, int>> q;
				memset(visit, 0, sizeof(visit));
				visit[i][j] = 1;
				q.push({ i,j });
				int res = -1;
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();
					res = max(res, visit[a][b] - 1);
					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] == 1) {
							visit[nx][ny] = visit[a][b] + 1;
							q.push({ nx,ny });
						}
					}
				}
				if (res)ans = max(ans, res);
			}
		}
	}
	cout << ans;
}