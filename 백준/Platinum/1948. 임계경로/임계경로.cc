#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int n, m, s, d;
int meetTime;
vector<vector<pair<int, int>>> v;
vector<vector<pair<int, int>>> rev;
vector<int> dis;
void dijk() {
	dis.resize(n + 1);
	priority_queue<pair<int, int>> q;
	q.push({ 0,s });
	while (!q.empty()) {
		int node = q.top().second;
		int cost = q.top().first;
		q.pop();

		if (dis[node] > cost) continue;

		for (auto& i : v[node]) {
			if (cost + i.second > dis[i.first]) {
				dis[i.first] = cost + i.second;
				q.push({ cost + i.second, i.first });
			}
		}
	}
	meetTime = dis[d];
}
int visit[10001];
int ans;
void dfs(int pre, int node, int cost) {
	if (node == s) {
		return;
	}
	visit[node] = 1;
	for (auto& i : rev[node]) {
		if (cost + i.second + dis[i.first] == meetTime) {
			ans++;
			if (!visit[i.first]) {
				dfs(node, i.first, cost + i.second);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	rev.resize(n + 1);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		rev[b].push_back({ a,c });
	}
	cin >> s >> d;
	dijk();
	dfs(d, d, 0);
	cout << meetTime << '\n' << ans << '\n';
}