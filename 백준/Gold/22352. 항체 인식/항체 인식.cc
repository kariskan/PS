#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<int>> map2;
int visit[30][30];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int main() {
	cin >> n >> m;
	map.resize(n, vector<int>(m));
	map2.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map2[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != map2[i][j]) {
				vector<vector<int>> t = map;
				queue<pair<int, int>> q;
				visit[i][j] = 1;
				q.push({ i,j });
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();
					t[a][b] = map2[i][j];
					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] == map[a][b]) {
							visit[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
				for (int i1 = 0; i1 < n; i1++) {
					for (int j1 = 0; j1 < m; j1++) {
						if (t[i1][j1] != map2[i1][j1]) {
							cout << "NO";
							return 0;
						}
					}
				}
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "YES";
}