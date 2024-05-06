#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> v(n + 1), rev(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		rev[b].push_back({ a,c });
	}

	int s, e;
	cin >> s >> e;

	priority_queue<pair<int, int>> pq;
	vector<int> dis(n + 1);

	pq.push({ 0, s });

	while (!pq.empty()) {
		int node = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		for (auto& i : v[node]) {
			int nxNode = i.first;
			int nxCost = cost + i.second;
			if (dis[nxNode] < nxCost) {
				dis[nxNode] = nxCost;
				pq.push({ nxCost, nxNode });
			}
		}
	}
	int cost = dis[e], cnt = 0;
	cout << cost << '\n';

	queue<int> q;
	vector<int> vis(n + 1);
	q.push(e);
	vis[e] = 1;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (auto& i : rev[node]) {
			if (dis[node] - i.second == dis[i.first]) {
				cnt++;
				if (!vis[i.first]) {
					q.push(i.first);
					vis[i.first] = 1;
				}
			}
		}
	}
	cout << cnt;
}