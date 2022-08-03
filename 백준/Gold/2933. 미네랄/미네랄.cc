#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
char map[100][100];

int getLeft(int i) {
	for (int j = 0; j < m; j++) {
		if (map[i][j] == 'x')return j;
	}
	return -1;
}

int getRight(int i) {
	for (int j = m - 1; j >= 0; j--) {
		if (map[i][j] == 'x')return j;
	}
	return -1;
}
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
void go(int r, int c) {
	map[r][c] = '.';
	int visit[100][100] = { 0, }, visit2[100][100] = { 0, };
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && map[i][j] == 'x') {
				cnt++;
				queue<pair<int, int>> q;
				q.push({ i,j });
				visit[i][j] = cnt;
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] == 'x') {
							q.push({ nx,ny });
							visit[nx][ny] = cnt;
						}
					}
				}
			}
		}
	}
	vector<int> num;
	vector<vector<pair<int, int>>> q2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'x' && !visit2[i][j]) {
				int minH = -1;
				queue<pair<int, int>> q;
				q.push({ i,j });
				visit2[i][j] = 1;
				q2.push_back({});
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();

					q2[q2.size() - 1].push_back({ a,b });
					visit2[a][b] = 1;

					for (int k = a; k < n; k++) {
						if (visit[a][b] == visit[k + 1][b])break;
						if (map[k + 1][b] == 'x' || k == n - 1) {
							if (minH == -1 || minH > k - a) {
								minH = k - a;
							}
							break;
						}
					}

					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit2[nx][ny] && map[nx][ny] == 'x') {
							visit2[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
				if (minH > 0) {
					sort(q2[q2.size() - 1].begin(), q2[q2.size() - 1].end());
					num.push_back(minH);
				}
				else q2.pop_back();
			}
		}
	}

	for (int i = 0; i < q2.size(); i++) {
		while (!q2[i].empty()) {
			int a = q2[i].back().first;
			int b = q2[i].back().second;
			map[a][b] = '.';
			map[a + num[i]][b] = 'x';
			q2[i].pop_back();
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		int l;
			if (i % 2 == 0) { //왼쪽
			l = getLeft(n - a);
		}
		else {
			l = getRight(n - a);
		}
		if (l != -1) {
			go(n - a, l);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}