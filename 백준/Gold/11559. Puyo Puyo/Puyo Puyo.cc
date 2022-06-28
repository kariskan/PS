#include <iostream>
#include <vector>
#include <queue>
using namespace std;
char map[12][6];
int n = 12, m = 6;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
bool bfs() {
	bool ok = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != '.') {
				queue<pair<int, int>> q;
				vector<pair<int, int>> v;
				int visit[12][6] = { 0, };
				v.push_back({ i,j });
				q.push({ i,j });
				visit[i][j] = 1;
				int cnt = 0;
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[a][b] == map[nx][ny]) {
							visit[nx][ny] = 1;
							q.push({ nx,ny });
							v.push_back({ nx,ny });
						}
					}
				}
				if (v.size() >= 4) {
					ok = true;
					for (int k = 0; k < v.size(); k++) {
						map[v[k].first][v[k].second] = '.';
					}
				}
			}
		}
	}



	for (int j1 = 0; j1 < m; j1++) {
		queue<char> t;
		for (int i1 = n - 1; i1 >= 0; i1--) {
			if (map[i1][j1] != '.') {
				t.push(map[i1][j1]);
				map[i1][j1] = '.';
			}
		}
		int idx = n - 1;
		while (!t.empty()) {
			map[idx--][j1] = t.front();
			t.pop();
		}
	}
	return ok;
}

int main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0;; i++) {
		if (!bfs()) {
			cout << i; break;
		}
	}
}