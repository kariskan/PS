#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int t, n, m, key[26], visit[102][102];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
char map[102][102];
string q;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
					map[i][j] = '.';
				}
				else {
					cin >> map[i][j];
				}
			}
		}

		cin >> q;
		for (char& c : q)key[c - 'a'] = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] >= 'A' && map[i][j] <= 'Z' && key[map[i][j] - 'A'])map[i][j] = '.';
			}
		}
		
		int ans = 0;
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		visit[0][0] = 1;

		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = a + x[k];
				int ny = b + y[k];

				if (nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1 && map[nx][ny] != '*' && !visit[nx][ny]) {
					if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z') {
						key[map[nx][ny] - 'a'] = 1;
						map[nx][ny] = '.';

						while (!q.empty())q.pop();
						memset(visit, 0, sizeof(visit));

						q.push({ nx,ny });
						visit[nx][ny] = 1;
					}
					else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z' && key[map[nx][ny] - 'A']) {
						map[nx][ny] = '.';
						q.push({ nx,ny });
						visit[nx][ny] = 1;
					}
					else if (map[nx][ny] == '$') {
						map[nx][ny] = '.';
						ans++;
						q.push({ nx,ny });
						visit[nx][ny] = 1;
					}
					else if (map[nx][ny] == '.') {
						q.push({ nx,ny });
						visit[nx][ny] = 1;
					}
				}
			}
		}
		cout << ans << '\n';
		memset(key, 0, sizeof(key));
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));
	}
}