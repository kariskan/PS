#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int map[10][10], visit[10][10], cnt;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int parent[7];
vector<vector<pair<int, int>>> v(7);
vector<tuple<int, int, int>> v2;
int canConnect(int num1, int num2) { //다리 연결할 수 있는지 체크
	int res = 0;
	for (int i = 0; i < v[num1].size(); i++) {
		int v1X = v[num1][i].first;
		int v1Y = v[num1][i].second;
		for (int j = 0; j < v[num2].size(); j++) {
			int v2X = v[num2][j].first;
			int v2Y = v[num2][j].second;
			if (v1X != v2X && v1Y != v2Y)continue;
			if (v1X == v2X) {
				bool ok = true;
				for (int k = min(v1Y, v2Y) + 1; k < max(v1Y, v2Y); k++) {
					if (map[v1X][k]) {
						ok = false;
						break;
					}
				}
				if (ok && (res == 0 || res > max(v1Y, v2Y) - min(v1Y, v2Y) - 1) && max(v1Y, v2Y) - min(v1Y, v2Y) - 1 > 1) {
					res = max(v1Y, v2Y) - min(v1Y, v2Y) - 1;
				}
			}
			else if (v1Y == v2Y) {
				bool ok = true;
				for (int k = min(v1X, v2X) + 1; k < max(v1X, v2X); k++) {
					if (map[k][v1Y]) {
						ok = false;
						break;
					}
				}
				if (ok && (res == 0 || res > max(v1X, v2X) - min(v1X, v2X) - 1) && max(v1X, v2X) - min(v1X, v2X) - 1 > 1) {
					res = max(v1X, v2X) - min(v1X, v2X) - 1;
				}
			}
		}
	}
	return res;
}

int find(int x) {
	if (parent[x] == x) return parent[x];
	else return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a > b)parent[a] = b;
	else parent[b] = a;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] && !visit[i][j]) {
				queue<pair<int, int>> q;
				cnt++;
				q.push({ i,j });
				visit[i][j] = 1;
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();
					map[a][b] = cnt;
					v[cnt].push_back({a,b});
					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny]) {
							visit[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= cnt; i++) {
		for (int j = i + 1; j <= cnt; j++) {
			int can = canConnect(i, j);
			if (can != 0) {
				v2.push_back({ can, i, j });
			}
		}
	}

	for (int i = 1; i <= cnt; i++)parent[i] = i;
	sort(v2.begin(), v2.end());
	int ans = 0;
	for (int i = 0; i < v2.size(); i++) {
		int cost, x, y;
		tie(cost, x, y) = v2[i];
		if (cost > 1 && find(x) != find(y)) {
			Union(x, y);
			ans += cost;
		}
	}
	for (int i = 2; i <= cnt; i++) {
		if (find(1) != find(i)) {
			cout << -1;
			return 0;
		}
	}
	cout << ans;
}