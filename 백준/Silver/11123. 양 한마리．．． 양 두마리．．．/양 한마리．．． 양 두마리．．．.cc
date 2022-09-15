#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m;
		queue<pair<int, int>> q;
		char map[100][100] = { 0, };
		int visit[100][100] = { 0, };

		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
			}
		}
		int ans = 0;
		int x[4] = { 0,0,1,-1 };
		int y[4] = { 1,-1,0,0 };

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visit[i][j] && map[i][j] == '#') {
					visit[i][j] = 1;
					q.push({ i,j });
					ans++;
					while (!q.empty()) {
						int a = q.front().first;
						int b = q.front().second;
						q.pop();

						for (int k = 0; k < 4; k++) {
							int nx = a + x[k];
							int ny = b + y[k];
							if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] == '#') {
								q.push({ nx,ny });
								visit[nx][ny] = 1;
							}
						}
					}
				}
			}
		}

		cout << ans << '\n';
	}
}