#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
char map[1000][1000];
int visit[1000][1000], visit2[1000][1000];
int main() {
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> m >> n;
		queue<pair<int, int>> q;
		queue<pair<int, int>> f;
		int ok = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					q.push({ i,j });
					visit[i][j] = 1;
				}
				if (map[i][j] == '*') {
					f.push({ i,j });
					visit2[i][j] = 1;
				}
			}
		}
		while (!q.empty() || !f.empty()) {
			queue<pair<int, int>> temp;
			while (!f.empty()) {
				int a = f.front().first;
				int b = f.front().second;
				f.pop();

				for (int k = 0; k < 4; k++) {
					int nx = a + x[k];
					int ny = b + y[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit2[nx][ny] && map[nx][ny] == '.') {
						map[nx][ny] = '*';
						visit2[nx][ny] = 1;
						temp.push({ nx,ny });
					}
				}
			}
			while (!temp.empty()) {
				f.push(temp.front());
				temp.pop();
			}

			while (!q.empty()) {
				int a = q.front().first;
				int b = q.front().second;
				q.pop();
				if (a == 0 || a == n - 1 || b == 0 || b == m - 1) {
					cout << visit[a][b] << '\n';
					ok = 1;
					break;
				}
				for (int k = 0; k < 4; k++) {
					int nx = a + x[k];
					int ny = b + y[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '.' && !visit[nx][ny]) {
						visit[nx][ny] = visit[a][b] + 1;
						temp.push({ nx,ny });
					}
				}
			}
			if (ok) {
				break;
			}
			while (!temp.empty()) {
				q.push(temp.front());
				temp.pop();
			}
		}
		if (!ok)cout << "IMPOSSIBLE\n";
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		memset(visit2, 0, sizeof(visit2));
	}
}