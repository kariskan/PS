#include <iostream>
#include <queue>
using namespace std;
int map[101][101];
int visit[101][101];
int main() {
	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 0; i < d; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	int x[4] = { 0,0,1,-1 };
	int y[4] = { 1,-1,0,0 };
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] && !visit[i][j]) {
				visit[i][j] = 1;
				queue<pair<int, int>> q;
				q.push({ i,j });
				int cnt = 0;
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();
					cnt++;
					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx > 0 && nx <= n && ny > 0 && ny <= m && !visit[nx][ny] && map[nx][ny] == 1) {
							visit[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans;
}