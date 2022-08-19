#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> dis;
vector<vector<pair<int, int>>> v;
priority_queue<pair<int, int>> q;

int main() {

	cin >> n >> m;
	v.resize(n + 1);
	dis.resize(n + 1, 987654321);

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	q.push({ 0,1 });
	dis[1] = 0;

	while (!q.empty()) {
		int cost = -q.top().first;
		int node = q.top().second;
		q.pop();

		if (dis[node] < cost) continue;

		for (auto& i : v[node]) {
			if (dis[i.first] > cost + i.second) {
				dis[i.first] = cost + i.second;
				q.push({ -cost - i.second, i.first });
			}
		}
	}

	cout << dis[n];
}