#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int ans = 1;
int x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 };
int n, m;
typedef struct map {
	bool on;
	vector<pair<int, int>> v;
};

int visit[101][101];
map light[101][101];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		light[x][y].v.push_back({ a,b });
	}
	light[1][1].on = true;
	visit[1][1] = 1;
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		vector<pair<int, int>> t = light[a][b].v;
		for (int k = 0; k < t.size(); k++) {
			if (!light[t[k].first][t[k].second].on) {
				light[t[k].first][t[k].second].on = true;
				ans++;
				for (int l = 0; l < 4; l++) {
					int nx = t[k].first + x[l];
					int ny = t[k].second + y[l];
					if (nx > 0 && nx <= n && ny > 0 && ny <= n && visit[nx][ny]) {
						visit[t[k].first][t[k].second] = 1;
						q.push({ t[k].first,t[k].second });
					}
				}
			}
		}
		for (int l = 0; l < 4; l++) {
			int nx = a + x[l];
			int ny = b + y[l];
			if (nx > 0 && nx <= n && ny > 0 && ny <= n && !visit[nx][ny] && light[nx][ny].on) {
				visit[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
	cout << ans;
}