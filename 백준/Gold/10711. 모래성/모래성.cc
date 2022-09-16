#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, near[1000][1000];
char map[1000][1000];
queue<pair<int, int>> q;
int x[8] = { -1,0,1,1,1,0,-1,-1 };
int y[8] = { 1,1,1,0,-1,-1,-1,0 };

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] >= '1' && map[i][j] <= '8') q.push({ i,j });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != '.') {
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					int nx = i + x[k];
					int ny = j + y[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '.') {
						cnt++;
					}
				}
				near[i][j] = cnt;
			}
		}
	}

	for (int t = 1;; t++) {

		queue<pair<int, int>> q2;

		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;

			q.pop();
			int cnt = 0;
			for (int k = 0; k < 8; k++) {
				int nx = a + x[k];
				int ny = b + y[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '.') {
					cnt++;
				}
			}

			if (cnt >= map[a][b] - '0') {
				q2.push({ a,b });
			}
		}

		if (q2.empty()) {
			cout << t - 1;
			break;
		}

		while (!q2.empty()) {
			int a = q2.front().first;
			int b = q2.front().second;
			q2.pop();

			map[a][b] = '.';

			for (int k = 0; k < 8; k++) {
				int nx = a + x[k];
				int ny = b + y[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] >= '1' && map[nx][ny] <= '8') {
					near[nx][ny]++;
					if (near[nx][ny] == map[nx][ny] - '0') {
						q.push({ nx,ny });
					}
				}
			}

		}

	}
}