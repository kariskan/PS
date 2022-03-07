#include <iostream>
#include <queue>
using namespace std;
int t;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int n, m;
vector<vector<int>> bfs(vector<string>& v, int a, int b) {
	vector<vector<int>> visit(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = -1;
		}
	}
	deque<pair<int, int>> q;
	q.push_back({ a,b });
	visit[a][b] = 0;
	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		q.pop_front();
		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && visit[nx][ny] == -1 && v[nx][ny] != '*') {
				if (v[nx][ny] == '#') {
					visit[nx][ny] = visit[a][b] + 1;
					q.push_back({ nx,ny });
				}
				else {
					visit[nx][ny] = visit[a][b];
					q.push_front({ nx,ny });
				}
			}
		}
	}
	return visit;
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<string> v(n + 2);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			v[i] = "." + v[i] + ".";
		}
		n += 2;
		m += 2;
		for (int j = 0; j < m; j++) {
			v[0] += ".";
			v[n - 1] += ".";
		}
		vector<vector<int>> d = bfs(v, 0, 0);
		int x1, y1, x2, y2;
		x1 = y1 = x2 = y2 = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == '$') {
					if (x1 == -1) {
						x1 = i;
						y1 = j;
					}
					else {
						x2 = i;
						y2 = j;
					}
				}
			}
		}
		vector<vector<int>> d1 = bfs(v, x1, y1);
		vector<vector<int>> d2 = bfs(v, x2, y2);
		int ans = 10001;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == '*')continue;
				if (d[i][j] == -1 || d1[i][j] == -1 || d2[i][j] == -1)continue;
				int temp = d[i][j] + d1[i][j] + d2[i][j];
				if (v[i][j] == '#')temp -= 2;
				ans = min(ans, temp);
			}
		}
		cout << ans << "\n";
	}
}