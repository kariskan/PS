#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m, a, b, c;
vector<vector<pair<int, int>>> v;

int main() {
	cin >> n >> m >> a >> b >> c;
	v.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int v1, v2, money;
		cin >> v1 >> v2 >> money;
		v[v1].push_back({ v2,money });
		v[v2].push_back({ v1,money });
	}

	priority_queue<tuple<int, int, int>> q;
	vector<int> dis(n + 1, 987654321);
	q.push({ 0,0,a });
	dis[a] = 0;

	while (!q.empty()) {
		int node, cost, shame;
		tie(cost, shame, node) = q.top();
		q.pop();

		for (auto& i : v[node]) {
			int nxNode = i.first;
			int nxCost = i.second + cost;
			int nxShame = max(i.second, shame);
			if (nxShame < dis[nxNode] && nxCost <= c) {
				dis[nxNode] = nxShame;
				q.push({ nxCost,nxShame,nxNode });
			}
		}
	}

	if (dis[b] == 987654321) cout << -1;
	else cout << dis[b];
}