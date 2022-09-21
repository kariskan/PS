#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m, dis[100001];
vector<vector<pair<int, int>>> v;

int main() {
	cin >> n >> m;
	v.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		dis[i] = 987654321;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	int s, t; cin >> s >> t;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	dis[s] = 0;

	while (!pq.empty()) {
		long long cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (cost > dis[node]) continue;

		for (auto& i : v[node]) {
			if (dis[i.first] > cost + i.second) {
				dis[i.first] = cost + i.second;
				pq.push({ -cost - i.second,i.first });
			}
		}
	}

	cout << dis[t];
}