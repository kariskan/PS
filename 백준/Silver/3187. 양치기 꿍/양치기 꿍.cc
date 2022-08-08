#include <iostream>
#include <queue>
using namespace std;

int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
char map[250][250];
int visit[250][250];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int v = 0, k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && map[i][j] != '#') {
				queue<pair<int, int>> q;
				visit[i][j] = 1;
				q.push({ i,j });
				int tv = 0, tk = 0;
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();

					if (map[a][b] == 'v')tv++;
					if (map[a][b] == 'k')tk++;

					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] != '#') {
							visit[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
				if (tv >= tk)v += tv;
				else k += tk;
			}
		}
	}
	cout << k << ' ' << v;
}