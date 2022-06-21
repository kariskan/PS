#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, t;
int map[100][100];
vector<vector<int>> v;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int visit[100][100];
int dis = 100;
bool run(int i, int j) {
	if (i == n - 1)return true;
	for (int k = 0; k < 4; k++) {
		int nx = i + x[k];
		int ny = j + y[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny]) {
			visit[nx][ny] = 1;
			if (run(nx, ny))return true;
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			if (c == 'x')map[i][j] = 1;
		}
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a; cin >> a;
		int idx = -1;
		dis = 100;
		if (i % 2 == 0) {
			for (int j = 0; j < m; j++) {
				if (map[n - a][j]) {
					map[n - a][j] = 0;
					idx = j;
					break;
				}
			}
		}
		else {
			for (int j = m - 1; j >= 0; j--) {
				if (map[n - a][j]) {
					map[n - a][j] = 0;
					idx = j;
					break;
				}
			}
		}
		if (idx != -1) {
			for (int k = 0; k < 4; k++) {
				int nx = n - a + x[k];
				int ny = idx + y[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny]) {
					visit[nx][ny] = 1;
					if (!run(nx, ny)) {
						for (int j1 = 0; j1 < m; j1++) {
							for (int i1 = n - 1; i1 >= 0; i1--) {
								if (visit[i1][j1]) {
									int temp = 0;
									for (int k = i1 + 1; k < n; k++) {
										if (map[k][j1] && !visit[k][j1])break;
										temp++;
									}
									if (temp != 0)
										dis = min(temp, dis);
								}
							}
						}
						for (int i1 = n - 1; i1 >= 0; i1--) {
							for (int j1 = 0; j1 < m; j1++) {
								if (visit[i1][j1]) {
									map[i1 + dis][j1] = map[i1][j1];
									map[i1][j1] = 0;
								}
							}
						}
						break;
					}
					memset(visit, false, sizeof(visit));
					dis = 100;
				}
			}
			memset(visit, false, sizeof(visit));
			dis = 100;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j])cout << 'x';
			else cout << '.';
		}
		cout << '\n';
	}
}